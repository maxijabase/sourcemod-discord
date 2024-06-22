public int Native_DiscordBot_DeleteMessageID(Handle plugin, int numParams)
{
    // Get native params
    DiscordBot bot = GetNativeCell(1);
    char channelId[64];
    GetNativeString(2, channelId, sizeof(channelId));
    char messageId[64];
    GetNativeString(3, messageId, sizeof(messageId));
    Function cb = GetNativeCell(4);
    any data = GetNativeCell(5);
    
    // DataPack
    DataPack pack = new DataPack();
    pack.WriteCell(bot);
    pack.WriteCell(plugin);
    pack.WriteFunction(cb);
    pack.WriteCell(data);
    
    // Make URL
    char url[128];
    Format(url, sizeof(url), "https://discord.com/api/channels/%s/messages/%s", channelId, messageId);

    // Create and send request
    DiscordRequest request = new DiscordRequest(url);
    request.SetBot(bot);
    request.Delete(OnMessageDeleted, pack);
    return 0;
}

public void OnMessageDeleted(HTTPResponse response, DataPack pack, const char[] error)
{
    if (response.Status != HTTPStatus_OK)
    {
        LogError("Couldn't Send DeleteMessageID - HTTP %i\n%s", response.Status, error);
        delete pack;
        return;
    }

    pack.Reset();
    DiscordBot bot = view_as<DiscordBot>(pack.ReadCell());
    Handle plugin = pack.ReadCell();
    Function cb = pack.ReadFunction();
    any data = pack.ReadCell();

    Call_StartFunction(plugin, cb);
    Call_PushCell(bot);
    Call_PushCell(data);
    Call_Finish();
}
