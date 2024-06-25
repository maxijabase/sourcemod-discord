methodmap DiscordChannel < JSONObject
{
    public DiscordChannel()
    {
        JSONObject obj = new JSONObject();
        return view_as<DiscordChannel>(obj);
    }
    
    property int Position
    {
        public get()
        {
            return this.GetInt("position");
        }
    }
    
    property bool IsPrivate
    {
        public get()
        {
            return this.GetBool("is_private");
        }
    }
    
    property ChannelType Type
    {
        public get()
        {
            return view_as<ChannelType>(this.GetInt("type"));
        }
    }
    
    property int Bitrate
    {
        public get()
        {
            return this.GetInt("bitrate");
        }
    }
    
    property int UserLimit
    {
        public get()
        {
            return this.GetInt("user_limit");
        }
    }
    
    property bool IsText
    {
        public get()
        {
            return this.Type == GUILD_TEXT;
        }
    }
    
    public void GetGuildID(char[] buffer, int maxlength)
    {
        this.GetString("guild_id", buffer, maxlength);
    }
    
    public void GetID(char[] buffer, int maxlength)
    {
        this.GetString("id", buffer, maxlength);
    }
    
    public void GetName(char[] buffer, int maxlength)
    {
        this.GetString("name", buffer, maxlength);
    }
    
    public void GetTopic(char[] buffer, int maxlength)
    {
        this.GetString("topic", buffer, maxlength);
    }
    
    public void GetLastMessageID(char[] buffer, int maxlength)
    {
        this.GetString("last_message_id", buffer, maxlength);
    }
    
    public void SetLastMessageID(const char[] id)
    {
        this.SetString("last_message_id", id);
    }
};

methodmap DiscordChannelList < JSONArray
{
    public DiscordChannel Get(int i)
    {
        return view_as<DiscordChannel>(this.Get(i));
    }
}

enum ChannelType
{
    GUILD_TEXT = 0, 
    DM, 
    GUILD_VOICE, 
    GROUP_DM, 
    GUILD_CATEGORY
}; 