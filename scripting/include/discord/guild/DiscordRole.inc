methodmap DiscordRole < JSONObject
{
	public void GetID(char[] buffer, int maxlength)
	{
		this.GetString("id", buffer, maxlength);
	}
	
	public void GetName(char[] buffer, int maxlength)
	{
		this.GetString("name", buffer, maxlength);
	}
	
	public int GetColor()
	{
		return this.GetInt("color");
	}
	
	public int GetPosition()
	{
		return this.GetInt("position");
	}
	
	public int GetPermissions()
	{
		return this.GetInt("permissions");
	}
	
	public bool Hoist()
	{
		return this.GetBool("hoist");
	}
	
	public bool Managed()
	{
		return this.GetBool("managed");
	}
	
	public bool Mentionable()
	{
		return this.GetBool("mentionable");
	}
};

methodmap DiscordRoleList < JSONArray
{
	public DiscordRole Get(int i)
	{
		return view_as<DiscordRole>(this.Get(i));
	}
};