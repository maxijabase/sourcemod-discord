methodmap DiscordBot < JSONObject
{
    public DiscordBot(const char[] token)
    {
        JSONObject json = new JSONObject();
        json.SetString("token", token);
        return view_as<DiscordBot>(json);
    }
    
    property float MessageCheckInterval
    {
        public get()
        {
            return this.GetFloat("messageCheckInterval");
        }
        
        public set(float value)
        {
            this.SetFloat("messageCheckInterval", value);
        }
    }
    
    property DiscordBotListeningChannels ListeningChannels
    {
        public get()
        {
            return view_as<DiscordBotListeningChannels>(this.Get("listeningChannels"));
        }
        
        public set(DiscordBotListeningChannels channels)
        {
            this.ListeningChannels = channels;
        }
    }
    
    public native void SendMessage(DiscordMessageSentResponseCallback callback, DiscordChannel channel, DiscordMessage message, any data = 0);
    public native void EditMessage(DiscordMessageEditedResponseCallback callback, DiscordChannel channel, DiscordMessage message, DiscordMessage newMessage, any data = 0);
    public native void DeleteMessage(DiscordMessageDeletedResponseCallback callback, DiscordChannel channel, DiscordMessage message, any data = 0);
    public native void GetGuilds(DiscordGuildsResponseCallback callback, any data = 0);
    public native void GetGuildChannels(DiscordGuildChannelsResponseCallback callback, DiscordGuild guild, any data = 0);
    public native void GetGuildMembers(DiscordGuildMembersResponseCallback callback, DiscordGuild guild, int limit = 1, char[] afterUserId = "", any data = 0);
    public native void GetGuildRoles(DiscordGuildRolesResponseCallback callback, DiscordGuild guild, any data = 0);
};

methodmap DiscordBotListeningChannels < DiscordChannelList
{
    public void StartListening(DiscordBot bot, DiscordChannel channel, DiscordMessageReceivedResponseCallback callback)
    {
        this.Push(channel);
        StartListeningToChannel(bot, channel, callback);
    }
    
    public void StopListening(const char[] id)
    {
        if (!this.Length)
        {
            return;
        }
        
        for (int i = 0; i <= this.Length; i++)
        {
            DiscordChannel tempChannel = this.Get(i);
            char id1[32];
            tempChannel.GetID(id1, sizeof(id1));
            if (!strcmp(id, id1))
            {
                this.Remove(i);
                break;
            }
        }
    }
    
    public bool IsListening(DiscordChannel channel)
    {
        bool exists = false;
        char id[32];
        channel.GetID(id, sizeof(id))
        for (int i = 0; i <= this.Length; i++)
        {
            DiscordChannel tempChannel = this.Get(i);
            char id1[32];
            tempChannel.GetID(id1, sizeof(id1));
            if (!strcmp(id, id1))
            {
                exists = true;
                break;
            }
        }
        return exists;
    }
    
    public void Clear()
    {
        if (this && this.Length)
        {
            this.Clear();
        }
    }
}

native void StartListeningToChannel(DiscordBot bot, DiscordChannel channel, DiscordMessageReceivedResponseCallback callback);
