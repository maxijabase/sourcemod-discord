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
    }

    public void SendMessage(DiscordMessageSentResponseCallback callback, char[] channel, char[] message, any data = 0)
    {
        SendMessage(this, callback, channel, message, data);
    }

    public void DeleteMessage(DiscordMessageDeletedResponseCallback callback, char[] channel, char[] messageId, any data = 0)
    {
        DeleteMessage(this, callback, channel, messageId, data);
    }

    public void EditMessage(DiscordMessageEditedResponseCallback callback, char[] channel, char[] messageId, char[] newValue, any data = 0)
    {
        EditMessage(this, callback, channel, messageId, newValue, data);
    }

    public void GetGuilds(DiscordGuildsResponseCallback callback, any data = 0)
    {
        GetGuilds(this, callback, data);
    }

    public void GetGuildChannels(DiscordGuildChannelsResponseCallback callback, DiscordGuild guild, any data = 0)
    {
        GetGuildChannels(this, callback, guild, data);
    }

    public void GetGuildMembers(DiscordGuildMembersResponseCallback callback, DiscordGuild guild, int limit = 1, char[] afterUserId = "", any data = 0)
    {
        GetGuildMembers(this, callback, guild, limit, afterUserId, data);
    }

    public void GetGuildRoles(DiscordGuildRolesResponseCallback callback, DiscordGuild guild, any data = 0)
    {
        GetGuildRoles(this, callback, guild, data);
    }
};

methodmap DiscordBotListeningChannels < DiscordChannelList
{
    public native void StartTimer(DiscordChannel channel, DiscordMessageReceivedResponseCallback callback);

    public void Start(DiscordChannel channel, DiscordMessageReceivedResponseCallback callback)
    {
        this.Push(channel);
        this.StartTimer(channel, callback);
    }

    public void Stop(const char[] id)
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

    public void StopAll()
    {
        if (this && this.Length)
        {
            this.Clear();
        }
    }
}

native void SendMessage(DiscordBot bot, DiscordMessageSentResponseCallback callback, char[] channel, char[] message, any data = 0);
native void DeleteMessage(DiscordBot bot, DiscordMessageDeletedResponseCallback callback, char[] channel, char[] messageId, any data = 0);
native void EditMessage(DiscordBot bot, DiscordMessageEditedResponseCallback callback, char[] channel, char[] messageId, char[] newValue, any data = 0);
native void GetGuilds(DiscordBot bot, DiscordGuildsResponseCallback callback, any data = 0);
native void GetGuildChannels(DiscordBot bot, DiscordGuildChannelsResponseCallback callback, DiscordGuild guild, any data = 0);
native void GetGuildMembers(DiscordBot bot, DiscordGuildMembersResponseCallback callback, DiscordGuild guild, int limit = 1, char[] afterUserId = "", any data = 0);
native void GetGuildRoles(DiscordBot bot, DiscordGuildRolesResponseCallback callback, DiscordGuild guild, any data = 0);