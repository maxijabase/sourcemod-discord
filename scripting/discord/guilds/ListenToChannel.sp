public int Native_StartListeningToChannel(Handle plugin, int numParams)
{
    // Get native params
    DiscordBot bot = GetNativeCell(1);
    DiscordChannel channel = GetNativeCell(2);
    Function cb = GetNativeCell(3);
    any data = GetNativeCell(4);
    
    // Create object and store info to pass it around the timer
    JSONObject listenInfo = new JSONObject();
    listenInfo.SetInt("bot", view_as<int>(bot));
    listenInfo.SetInt("channel", view_as<int>(channel));
    listenInfo.SetInt("cb", view_as<int>(cb));
    listenInfo.SetInt("plugin", view_as<int>(plugin));
    listenInfo.SetInt("data", view_as<int>(data));
    
    // Call
    GetMessages(listenInfo);
    
    return 0;
}

public void GetMessages(JSONObject listenInfo)
{
    // Check if we're still listening to this channel
    DiscordBot bot = view_as<DiscordBot>(listenInfo.GetInt("bot"));
    DiscordChannel channel = view_as<DiscordChannel>(listenInfo.GetInt("channel"));
    if (!bot.ListeningChannels.IsListening(channel))
    {
        return;
    }
    
    // Make URL
    char channelId[32];
    channel.GetID(channelId, sizeof(channelId));
    
    char lastMessageId[32];
    channel.GetLastMessageID(lastMessageId, sizeof(lastMessageId));
    
    char url[256];
    Format(url, sizeof(url), "https://discord.com/api/channels/%s/messages", channelId);
    
    // Create and send request
    DiscordRequest req = new DiscordRequest(url);
    req.SetBot(bot);
    req.AppendQueryParam("after", lastMessageId);
    req.AppendQueryParam("limit", "%i", 100);
    req.Get(OnMessagesReceived, listenInfo);
}

public void OnMessagesReceived(HTTPResponse response, JSONObject listenInfo, const char[] error)
{
    if (response.Status != HTTPStatus_OK)
    {
        LogError("Couldn't Get Messages - HTTP %i\n%s", response.Status, error);
        delete listenInfo;
        return;
    }
    
    DiscordBot bot = view_as<DiscordBot>(listenInfo.GetInt("bot"));
    DiscordChannel channel = view_as<DiscordChannel>(listenInfo.GetInt("channel"));
    Handle plugin = view_as<Handle>(listenInfo.GetInt("plugin"));
    Function cb = view_as<Function>(listenInfo.GetInt("cb"));
    any data = view_as<any>(listenInfo.GetInt("data"));
    
    DiscordMessageList messages = view_as<DiscordMessageList>(response.Data);
    
    if (messages.Length > 0)
    {
        // There are new messages
        for (int i = messages.Length - 1; i >= 0; i--)
        {
            // Get message
            DiscordMessage msg = messages.Get(i);
            
            // Get message ID
            char msgId[32];
            msg.GetID(msgId, sizeof(msgId));
            
            // If it's the last message, set it to the channel
            if (i == 0)
            {
                channel.SetLastMessageID(msgId);
            }
            
            // Call native
            Call_StartFunction(plugin, cb);
            Call_PushCell(bot);
            Call_PushCell(channel);
            Call_PushCell(msg);
            Call_PushCell(data);
            Call_Finish();
        }
    }
    
    CreateTimer(bot.MessageCheckInterval, OnTimerElapsed, listenInfo);
}

public Action OnTimerElapsed(Handle timer, JSONObject listenInfo)
{
    GetMessages(listenInfo);
    return Plugin_Continue;
} 