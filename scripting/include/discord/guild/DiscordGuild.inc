methodmap DiscordGuild < JSONObject
{
    public void GetID(char[] buffer, int max)
    {
        this.GetString("id", buffer, max);
    }
    
    public void GetName(char[] buffer, int max)
    {
        this.GetString("name", buffer, max);
    }
    
    public void GetIcon(char[] buffer, int max)
    {
        this.GetString("icon", buffer, max);
    }
}

methodmap DiscordGuildList < JSONArray
{
    public DiscordGuild Get(int i)
    {
        return view_as<DiscordGuild>(this.Get(i));
    }
}

typeset DiscordGuildsResponseCallback
{
    function void(DiscordBot bot, DiscordGuildList guilds);
    function void(DiscordBot bot, DiscordGuildList guilds, any data);
}

typeset DiscordGuildChannelsResponseCallback
{
    function void(DiscordBot bot, DiscordGuild guild, DiscordChannelList channels);
    function void(DiscordBot bot, DiscordGuild guild, DiscordChannelList channels, any data);
}

typeset DiscordGuildRolesResponseCallback
{
    function void(DiscordBot bot, DiscordGuild guild, DiscordRoleList roles);
    function void(DiscordBot bot, DiscordGuild guild, DiscordRoleList roles, any data);
}

typeset DiscordGuildMembersResponseCallback
{
    function void(DiscordBot bot, DiscordGuild guild, DiscordGuildMemberList members);
    function void(DiscordBot bot, DiscordGuild guild, DiscordGuildMemberList members, any data);
} 