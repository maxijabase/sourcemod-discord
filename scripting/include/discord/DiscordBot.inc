methodmap DiscordBot < JSONObject
{
    public DiscordBot(const char[] token)
    {
        JSONObject json = new JSONObject();
        json.SetString("token", token);
        return view_as<DiscordBot>(json);
    }
    
    public void StopListening()
    {
        this.Remove("listeningChannels");
    }
    
    property float MessageCheckInterval
    {
        public get()
        {
            return this.GetFloat("messageInterval");
        }
        
        public set(float value)
        {
            this.SetFloat("messageInterval", value);
        }
    }

    public native void StartTimer(DiscordChannel channel, DiscordMessageReceivedResponseCallback callback);
    
    public JSONArray GetListeningChannels()
    {
        return view_as<JSONArray>(this.Get("listeningChannels"));
    }
    
    public void StartListeningToChannel(DiscordChannel channel, DiscordMessageReceivedResponseCallback callback)
    {
        if (this.IsListeningToChannel(channel))
        {
            return;
        }
        
        JSONArray channels = this.GetListeningChannels();
        
        if (channels == null)
        {
            channels = new JSONArray();
            this.Set("listeningChannels", channels);
        }
        
        channels.Push(channel);
        delete channels;
        this.StartTimer(channel, callback);
    }
    
    public bool IsListeningToChannel(DiscordChannel channel)
    {
        JSONArray channels = this.GetListeningChannels();
        if (channels == null)
        {
            return false;
        }
        
        static bool found = false;
        static char id[32];
        channel.GetID(id, sizeof(id));
        static DiscordChannel tempChannel;
        static char tempID[32];
        for (int i = 0; i < channels.Length; i++)
        {
            tempChannel = view_as<DiscordChannel>(channels.Get(i));
            tempChannel.GetID(tempID, sizeof(tempID));
            
            if (StrEqual(id, tempID, false))
            {
                found = true;
                break;
            }
        }
        
        delete tempChannel;
        delete channels;
        return found;
    }
    
    public bool IsListeningToChannelID(const char[] id)
    {
        JSONArray channels = this.GetListeningChannels();
        if (channels == null)
        {
            return false;
        }
        
        static bool found = false;
        static DiscordChannel tempChannel;
        static char tempID[32];
        for (int i = 0; i < channels.Length; i++)
        {
            tempChannel = view_as<DiscordChannel>(channels.Get(i));
            tempChannel.GetID(tempID, sizeof(tempID));
            
            if (StrEqual(id, tempID, false))
            {
                found = true;
                break;
            }
        }
        
        delete tempChannel;
        delete channels;
        return found;
    }
    
    public void StopListeningToChannel(DiscordChannel channel)
    {
        JSONArray channels = this.GetListeningChannels();
        if (channels == null)
        {
            return;
        }
        
        static char id[32];
        channel.GetID(id, sizeof(id));
        static char tempID[32];
        static DiscordChannel tempChannel;
        for (int i = 0; i < channels.Length; i++)
        {
            tempChannel = view_as<DiscordChannel>(channels.Get(i));
            tempChannel.GetID(tempID, sizeof(tempID));
            if (StrEqual(id, tempID, false))
            {
                channels.Remove(i);
                break;
            }
        }
        
        delete tempChannel;
        delete channels;
    }
    
    public void StopListeningToChannels()
    {
        JSONArray channels = this.GetListeningChannels();
        if (channels == null)
        {
            return;
        }
        
        channels.Clear();
        delete channels;
    }
    
    public void StopListeningToChannelID(const char[] id)
    {
        JSONArray channels = this.GetListeningChannels();
        if (channels == null)
        {
            return;
        }
        
        static char tempID[32];
        static DiscordChannel tempChannel;
        for (int i = 0; i < channels.Length; i++)
        {
            tempChannel = view_as<DiscordChannel>(channels.Get(i));
            tempChannel.GetID(tempID, sizeof(tempID));
            if (StrEqual(id, tempID, false))
            {
                channels.Remove(i);
                break;
            }
        }
        
        delete tempChannel;
        delete channels;
    }
    
    public DiscordChannel GetListeningChannelByID(const char[] id)
    {
        JSONArray channels = this.GetListeningChannels();
        if (channels == null)
        {
            return;
        }
        
        static DiscordChannel tempChannel;
        static char tempID[32];
        for (int i = 0; i < channels.Length; i++)
        {
            tempChannel = view_as<DiscordChannel>(channels.Get(i));
            tempChannel.GetID(tempID, sizeof(tempID));
            if (StrEqual(id, tempID, false))
            {
                delete channels;
                return tempChannel;
            }
        }
        
        delete channels;
        return null;
    }
    
    public native void AddReactionID(const char[] channel, const char[] messageId, const char[] emoji);
    
    public void AddReaction(DiscordChannel channel, const char[] messageId, const char[] emoji)
    {
        char channelid[64];
        channel.GetID(channelid, sizeof(channelid));
        this.AddReactionID(channelid, messageId, emoji);
    }
    
    public native void DeleteReactionID(const char[] channel, const char[] messageId, const char[] emoji, const char[] user);
    
    public void DeleteReaction(DiscordChannel channel, const char[] messageId, const char[] emoji, const char[] user)
    {
        char chid[64];
        channel.GetID(chid, sizeof(chid));
        this.DeleteReactionID(chid, messageId, emoji, user);
    }
    
    public void DeleteReactionSelf(DiscordChannel channel, const char[] messageId, const char[] emoji)
    {
        this.DeleteReaction(channel, messageId, emoji, "@me");
    }
    public void DeleteReactionAll(DiscordChannel channel, const char[] messageId, const char[] emoji)
    {
        this.DeleteReaction(channel, messageId, emoji, "@all");
    }
    
    public void DeleteReactionSelfID(const char[] channel, const char[] messageId, const char[] emoji)
    {
        this.DeleteReactionID(channel, messageId, emoji, "@me");
    }
    public void DeleteReactionAllID(const char[] channel, const char[] messageId, const char[] emoji)
    {
        this.DeleteReactionID(channel, messageId, emoji, "@all");
    }
    
    public native void GetToken(char[] token, int maxlength);
    
    public native void SendMessage(DiscordChannel channel, char[] message, DiscordMessageSentResponseCallback callback, any data = 0);
    
    public native void SendMessageToChannelID(char[] channel, char[] message, DiscordMessageSentResponseCallback callback, any data = 0);
    
    public native void DeleteMessageID(char[] channel, char[] message, DiscordMessageDeletedResponseCallback callback, any data = 0);
    public native void DeleteMessage(DiscordChannel channel, DiscordMessage message, DiscordMessageDeletedResponseCallback callback, any data = 0);
    
    public native void GetGuilds(DiscordGuildsResponseCallback callback, any data = 0);
    
    public native void GetGuildChannels(char[] guild, DiscordGuildChannelsResponseCallback callback, any data = 0);
    
    public native void GetGuildMembers(char[] guild, DiscordGuildMembersResponseCallback callback, int limit, char[] afterUserId = "", any data = 0);
    
    public native void GetGuildRoles(char[] guild, DiscordGuildRolesResponseCallback callback, any data = 0);
};
