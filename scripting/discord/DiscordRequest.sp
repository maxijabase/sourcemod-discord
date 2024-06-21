methodmap DiscordRequest < HTTPRequest
{
    public DiscordRequest(char[] url)
    {
        HTTPRequest req = new HTTPRequest(url);
        return view_as<DiscordRequest>(req);
    }
    
    public void SetBot(DiscordBot bot)
    {
        if (this == null)
        {
            return;
        }
        
        char token[128];
        bot.GetString("token", token, sizeof(token));
        this.SetHeader("Authorization", "Bot %s", token);
    }
}
