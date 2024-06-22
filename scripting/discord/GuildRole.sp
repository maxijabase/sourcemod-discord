public any Native_DiscordBot_GetGuildRoles(Handle plugin, int numParams)
{
    // Get native params
    DiscordBot bot = view_as<DiscordBot>(CloneHandle(GetNativeCell(1)));
    char guild[32];
    GetNativeString(2, guild, sizeof(guild));
    Function cb = GetNativeCell(3);
    any data = GetNativeCell(4);
    
    // DataPack
    DataPack pack = new DataPack();
    pack.WriteCell(bot);
    pack.WriteString(guild);
    pack.WriteFunction(cb);
    pack.WriteCell(plugin);
    pack.WriteCell(data);

    // Make URL
    char url[256];
    Format(url, sizeof(url), "https://discord.com/api/guilds/%s/roles", guild);
    
    // Create and send request
    DiscordRequest request = new DiscordRequest(url);
    request.SetBot(bot);
    request.Get(OnGuildsReceived, pack);
    return 0;
}

public void OnGuildsReceived(HTTPResponse response, DataPack pack, const char[] error)
{
    if (response.Status != HTTPStatus_OK)
    {
        LogError("Couldn't Send GetGuildRoles - HTTP %i\n%s", response.Status, error);
        delete pack;
        return;
    }

    pack.Reset();
    DiscordBot bot = view_as<DiscordBot>(pack.ReadCell());
    char guild[32];
    pack.ReadString(guild, sizeof(guild));
    Function cb = pack.ReadFunction();
    Handle plugin = pack.ReadCell();
    any data = pack.ReadCell();
    delete pack;

    Call_StartFunction(plugin, callback);
    Call_PushCell(bot);
    Call_PushString(guild);
    Call_PushCell(response.Data);
    Call_PushCell(data);
    Call_Finish();
}