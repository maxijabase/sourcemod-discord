public int Native_GetGuilds(Handle plugin, int numParams)
{
    // Get native params
    DiscordBot bot = GetNativeCell(1);
    Function cb = GetNativeCell(2);
    any data = GetNativeCell(3);
    
    // Datapack
    DataPack pack = new DataPack();
    pack.WriteCell(bot);
    pack.WriteCell(plugin);
    pack.WriteFunction(cb);
    pack.WriteCell(data);
    
    // Make URL
    char url[128];
    Format(url, sizeof(url), "https://discord.com/api/users/@me/guilds");
    
    // Create and send request
    DiscordRequest req = new DiscordRequest(url);
    req.SetBot(bot);
    req.Get(OnGuildsReceived, pack);
    
    return 0;
}

public void OnGuildsReceived(HTTPResponse response, DataPack pack, const char[] error)
{
    if (response.Status != HTTPStatus_OK)
    {
        LogError("Couldn't Send GetGuilds - HTTP %i\n%s", response.Status, error);
        delete pack;
        return;
    }
    
    pack.Reset();
    DiscordBot bot = view_as<DiscordBot>(pack.ReadCell());
    Handle plugin = pack.ReadCell();
    Function cb = pack.ReadFunction();
    any data = pack.ReadCell();
    delete pack;
    
    Call_StartFunction(plugin, cb);
    Call_PushCell(bot);
    Call_PushCell(response.Data);
    Call_PushCell(data);
    Call_Finish();
} 