methodmap DiscordGuild < JSONObject
{
    public void GetId(char[] buffer, int max)
    {
        return this.GetString("id", buffer, max);
    }

    public void GetName(char[] buffer, int max)
    {
        return this.GetString("name", buffer, max);
    }

    public void GetIcon(char[] buffer, int max)
    {
        return this.GetString("icon", buffer, max);
    }
}

methodmap DiscordGuildList < JSONArray
{
    public DiscordGuild Get(int i)
    {
        return view_as<DiscordGuild>(this.Get(i));
    }
}