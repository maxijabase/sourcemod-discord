public int Native_GetGuildChannels(Handle plugin, int numParams)
{
    // Get native params
    DiscordBot bot = GetNativeCell(1);
    Function cb = GetNativeCell(2);
    DiscordGuild guild = GetNativeCell(3);
    any data = GetNativeCell(4);
    
    // DataPack
    DataPack pack = new DataPack();
    pack.WriteCell(bot);
    pack.WriteFunction(cb);
    pack.WriteCell(plugin);
    pack.WriteCell(guild);
    pack.WriteCell(data);
    
    // Make URL
    char guildId[32];
    guild.GetID(guildId, sizeof(guildId));
    
    char url[128];
    Format(url, sizeof(url), "https://discord.com/api/guilds/%s/channels", guildId);
    
    // Create and send request
    DiscordRequest req = new DiscordRequest(url);
    req.SetBot(bot);
    req.Get(OnChannelsReceived, pack);
    
    return 0;
}

public void OnChannelsReceived(HTTPResponse response, DataPack pack, const char[] error)
{
    if (response.Status != HTTPStatus_OK)
    {
        LogError("Couldn't Send GetGuildChannels - HTTP %i\n%s", response.Status, error);
        delete pack;
        return;
    }
    
    pack.Reset();
    DiscordBot bot = view_as<DiscordBot>(pack.ReadCell());
    Function cb = pack.ReadFunction();
    Handle plugin = pack.ReadCell();
    DiscordGuild guild = view_as<DiscordGuild>(pack.ReadCell());
    any data = pack.ReadCell();
    delete pack;
    
    Call_StartFunction(plugin, cb);
    Call_PushCell(bot);
    Call_PushCell(guild);
    Call_PushCell(response.Data);
    Call_PushCell(data);
    Call_Finish();
} 