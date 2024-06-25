public int Native_GetGuildRoles(Handle plugin, int numParams)
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
    
    char url[256];
    Format(url, sizeof(url), "https://discord.com/api/guilds/%s/roles", guildId);
    
    // Create and send request
    DiscordRequest request = new DiscordRequest(url);
    request.SetBot(bot);
    request.Get(OnGuildRolesReceived, pack);
    return 0;
}

public void OnGuildRolesReceived(HTTPResponse response, DataPack pack, const char[] error)
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
    
    Call_StartFunction(plugin, cb);
    Call_PushCell(bot);
    Call_PushString(guild);
    Call_PushCell(response.Data);
    Call_PushCell(data);
    Call_Finish();
} 