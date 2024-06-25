methodmap DiscordUser < JSONObject
{
    public DiscordUser()
    {
        JSONObject obj = new JSONObject();
        return view_as<DiscordUser>(obj);
    }
    
    public void GetID(char[] buffer, int maxlength)
    {
        this.GetString("id", buffer, maxlength);
    }
    
    public void GetUsername(char[] buffer, int maxlength)
    {
        this.GetString("username", buffer, maxlength);
    }
    
    public void GetAvatar(char[] buffer, int maxlength)
    {
        this.GetString("avatar", buffer, maxlength);
    }
    
    public bool IsVerified()
    {
        return this.GetBool("verified");
    }
    
    public void GetEmail(char[] buffer, int maxlength)
    {
        this.GetString("email", buffer, maxlength);
    }
    
    public bool IsBot()
    {
        return this.GetBool("bot");
    }
}; 