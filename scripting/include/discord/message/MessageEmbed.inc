methodmap MessageEmbed < JSONObject
{
    public MessageEmbed()
    {
        JSONObject obj = new JSONObject();
        return view_as<MessageEmbed>(obj);
    }
    
    public int GetColor()
    {
        return this.GetInt("color");
    }
    
    public void SetColor(int color)
    {
        this.SetInt("color", color);
    }
    
    public bool GetTitle(char[] buffer, int maxlength)
    {
        return this.GetString("title", buffer, maxlength);
    }
    
    public void SetTitle(const char[] title)
    {
        this.SetString("title", title);
    }
    
    public bool GetTitleLink(char[] buffer, int maxlength)
    {
        return this.GetString("title_link", buffer, maxlength);
    }
    
    public void SetTitleLink(const char[] title_link)
    {
        this.SetString("title_link", title_link);
    }
    
    public bool GetImage(char[] buffer, int maxlength)
    {
        return this.GetString("image_url", buffer, maxlength);
    }
    
    public void SetImage(const char[] image_url)
    {
        this.SetString("image_url", image_url);
    }
    
    public bool GetAuthor(char[] buffer, int maxlength)
    {
        return this.GetString("author_name", buffer, maxlength);
    }
    
    public void SetAuthor(const char[] author_name)
    {
        this.SetString("author_name", author_name);
    }
    
    public bool GetAuthorLink(char[] buffer, int maxlength)
    {
        return this.GetString("author_link", buffer, maxlength);
    }
    
    public void SetAuthorLink(const char[] author_link)
    {
        this.SetString("author_link", author_link);
    }
    
    public bool GetAuthorIcon(char[] buffer, int maxlength)
    {
        return this.GetString("author_icon", buffer, maxlength);
    }
    
    public void SetAuthorIcon(const char[] author_icon)
    {
        this.SetString("author_icon", author_icon);
    }
    
    public bool GetThumb(char[] buffer, int maxlength)
    {
        return this.GetString("thumb_url", buffer, maxlength);
    }
    
    public void SetThumb(const char[] thumb_url)
    {
        this.SetString("thumb_url", thumb_url);
    }
    
    public bool GetFooter(char[] buffer, int maxlength)
    {
        return this.GetString("footer", buffer, maxlength);
    }
    
    public void SetFooter(const char[] footer)
    {
        this.SetString("footer", footer);
    }
    
    public bool GetFooterIcon(char[] buffer, int maxlength)
    {
        return this.GetString("footer_icon", buffer, maxlength);
    }
    
    public void SetFooterIcon(const char[] footer_icon)
    {
        this.SetString("footer_icon", footer_icon);
    }
    
    property JSONArray Fields
    {
        public get()
        {
            return view_as<JSONArray>(this.Get("fields"));
        }
        
        public set(JSONArray value)
        {
            this.Set("fields", value);
        }
    }
    
    public void AddField(const char[] name, const char[] value, bool inline)
    {
        JSONObject field = new JSONObject();
        field.SetString("name", name);
        field.SetString("value", value);
        field.SetBool("inline", inline);

        JSONArray fields = this.Fields;
        if (fields == null)
        {
            fields = new JSONArray();
        }

        fields.Push(field);
        this.Fields = fields;
    }
    
    // Below don't support Slack Mode
    public bool GetDescription(char[] buffer, int maxlength)
    {
        return this.GetString("description", buffer, maxlength);
    }
    
    public void SetDescription(const char[] description)
    {
        this.SetString("description", description);
    }
    
    public bool GetURL(char[] buffer, int maxlength)
    {
        return this.GetString("url", buffer, maxlength);
    }
    
    public void SetURL(const char[] url)
    {
        this.SetString("url", url);
    }
};
