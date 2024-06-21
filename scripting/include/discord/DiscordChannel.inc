methodmap DiscordChannel < JSONObject
{
    public DiscordChannel()
    {
        JSONObject obj = new JSONObject();
        return view_as<DiscordChannel>(obj);
    }
    
    public native void SendMessage(DiscordBot Bot, char[] message, OnMessageSent callback, any data = 0);
    
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
        json_object_set_new(this, "last_message_id", json_string(id));
    }
    
    property int Type
    {
        public get()
        {
            return this.GetInt("type");
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
};

enum
{
    GUILD_TEXT = 0, 
    DM, 
    GUILD_VOICE, 
    GROUP_DM, 
    GUILD_CATEGORY
}; 