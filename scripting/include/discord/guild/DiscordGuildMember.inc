// https://discord.com/developers/docs/resources/guild#guild-member-object-example-guild-member

methodmap DiscordGuildMember < JSONObject
{
    public DiscordUser GetUser()
    {
        return view_as<DiscordUser>(this.Get("user"));
    }
    
    public void GetNickname(char[] buffer, int maxlength)
    {
        this.GetString("nick", buffer, maxlength);
    }
    
    public JSONArray GetRoles()
    {
        return view_as<JSONArray>(this.Get("roles"));
    }
    
    public void GetJoinedAt(char[] buffer, int maxlength)
    {
        this.GetString("joined_at", buffer, maxlength);
    }
    
    public bool IsDeaf()
    {
        return this.GetBool("deaf");
    }
    
    public bool IsMute()
    {
        return this.GetBool("mute");
    }
};

methodmap DiscordGuildMemberList < JSONArray
{
    public DiscordGuildMember Get(int i)
    {
        return view_as<DiscordGuildMember>(this.Get(i));
    }
}
