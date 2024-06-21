methodmap DiscordWebHook < JSONObject
{
    public DiscordWebHook(char[] url)
    {
        JSONObject obj = new JSONObject();
        obj.SetString("__url", url);
        JSONObject data = new JSONObject();
        obj.Set(data);
        
        return view_as<DiscordWebHook>(obj);
    }
    
    public void GetUrl(char[] buffer, int maxlength)
    {
        this.GetString("__url", buffer, maxlength);
    }
    
    property bool SlackMode
    {
        public get()
        {
            return this.GetBool("__slack");
        }
        
        public set(bool value)
        {
            this.SetBool("__slack", value);
        }
    }
    
    property JSONObject Data
    {
        public get()
        {
            return this.Get("__data");
        }
        
        public set(JSONObject value)
        {
            this.Set("__data", value);
        }
    }
    
    public void Embed(MessageEmbed embed)
    {
        JSONObject data = this.Data;
        JSONArray embeds = data.Get("embeds");
        
        if (embeds == null)
        {
            embeds = new JSONArray();
            data.Set("embeds", embeds);
        }
        
        embeds.Push(embed);
        delete embeds;
        delete data;
    }
    
    property bool TTS
    {
        public get()
        {
            return this.Data.GetBool("tts");
        }
        
        public set(bool value)
        {
            this.Data.SetBool("tts", value);
        }
    }
    
    public bool GetUsername(char[] buffer, int maxlength)
    {
        return this.Data.GetString("username", buffer, maxlength);
    }
    
    public void SetUsername(const char[] name)
    {
        this.Data.SetString("username", name);
    }
    
    public bool GetAvatar(char[] buffer, int maxlength)
    {
        return this.Data.GetString("avatar_url", buffer, maxlength);
    }
    
    public void SetAvatar(const char[] icon_url)
    {
        this.Data.SetString("avatar_url", icon_url);
    }
    
    public bool GetContent(char[] buffer, int maxlength)
    {
        return this.Data.GetString("content", buffer, maxlength);
    }
    
    public void SetContent(const char[] content)
    {
        this.Data.SetString("content", content);
    }
    
    public native void Send();
};
