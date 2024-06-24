public int Native_DiscordBot_GetGuildMembers(Handle plugin, int numParams)
{
    // Get native params
    DiscordBot bot = GetNativeCell(1);
    DiscordGuild guild = GetNativeCell(2);
    Function cb = GetNativeCell(3);
    int limit = GetNativeCell(4);
    char after[32];
    GetNativeString(5, after, sizeof(after));
    any data = GetNativeCell(6);
    
    // Datapack
    DataPack pack = new DataPack();
    pack.WriteCell(bot);
    pack.WriteCell(guild);
    pack.WriteCell(plugin);
    pack.WriteFunction(cb);
    
    // Make URL
    char guildId[32];
    guild.GetID(guildId, sizeof(guildId));
    char url[256];
    Format(url, sizeof(url), "https://discord.com/api/guilds/%s/members", guildId);

    // Create and send request
    DiscordRequest req = new DiscordRequest(url);
    req.SetBot(bot);
    req.AppendQueryParam("limit", limit);
    if (after[0] != '\0')
    {
        req.AppendQueryParam("after", after);
    }

    req.Get(OnGuildMembersReceived, pack);
}

public void OnGuildMembersReceived(HTTPResponse response, DataPack pack, const char[] error)
{
    if (response.Status != HTTPStatus_OK)
    {
        LogError("Couldn't Send GetGuildMembers - HTTP %i\n%s", response.Status, error);
        delete pack;
        return;
    }

    pack.Reset();
    DiscordBot bot = view_as<DiscordBot>(pack.ReadCell());
    Function cb = pack.ReadFunction();
    Handle plugin = pack.ReadCell();

    Call_StartFunction(plugin, cb);
    Call_PushCell(bot);
    
}