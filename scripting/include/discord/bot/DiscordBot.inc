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

    public native void Discord_SendMessage(DiscordBot bot, DiscordMessageSentResponseCallback callback, DiscordChannel channel, DiscordMessage message, any data = 0);
    public native void Discord_EditMessage(DiscordBot bot, DiscordMessageEditedResponseCallback callback, DiscordChannel channel, DiscordMessage message, DiscordMessage newMessage, any data = 0);
    public native void Discord_DeleteMessage(DiscordBot bot, DiscordMessageDeletedResponseCallback callback, DiscordChannel channel, DiscordMessage message, any data = 0);
    public native void Discord_GetGuilds(DiscordBot bot, DiscordGuildsResponseCallback callback, any data = 0);
    public native void Discord_GetGuildChannels(DiscordBot bot, DiscordGuildChannelsResponseCallback callback, DiscordGuild guild, any data = 0);
    public native void Discord_GetGuildMembers(DiscordBot bot, DiscordGuildMembersResponseCallback callback, DiscordGuild guild, int limit = 1, char[] afterUserId = "", any data = 0);
    public native void Discord_GetGuildRoles(DiscordBot bot, DiscordGuildRolesResponseCallback callback, DiscordGuild guild, any data = 0);

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