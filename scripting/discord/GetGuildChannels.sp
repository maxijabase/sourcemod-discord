public int Native_DiscordBot_GetGuildChannels(Handle plugin, int numParams)
{
    // Get native params
    DiscordBot bot = GetNativeCell(1);
    char guild[32];
    GetNativeString(2, guild, sizeof(guild));
    Function cb = GetNativeCell(3);
    any data = GetNativeCell(4);

    // DataPack
    DataPack pack = new DataPack();
    pack.WriteCell(bot);
    pack.WriteString(guild);
    pack.WriteCell(plugin);
    pack.WriteFunction(cb);
    pack.WriteCell(data);
    
    // Make URL
    char url[64];
    Format(url, sizeof(url), "https://discord.com/api/guilds/%s/channels", guild);

    // Create and send request
    DiscordRequest req = new DiscordRequest(url);
    req.SetBot(bot);
    req.Get(OnChannelsReceived, pack);
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
    char guild[32];
    pack.ReadString(guild, sizeof(guild));
    Handle plugin = pack.ReadCell();
    Function cb = pack.ReadFunction();
    any data = pack.ReadCell();
    delete pack;

    Call_StartFunction(plugin, cb);
    Call_PushCell(bot);
    Call_PushString(guild);
    Call_PushCell(response.Data);
    Call_PushCell(data);
    Call_Finish();
}