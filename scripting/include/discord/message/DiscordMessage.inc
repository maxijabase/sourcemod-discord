methodmap DiscordMessage < JSONObject
{
	public void GetID(char[] buffer, int maxlength)
	{
		this.GetString("id", buffer, maxlength);
	}
	
	public bool IsPinned()
	{
		return this.GetBool("pinned");
	}
	
	public DiscordUser GetAuthor()
	{

	}
	
	public void GetContent(char[] buffer, int maxlength)
	{
		this.GetString("content", buffer, maxlength);
	}
	
	public void GetChannelID(char[] buffer, int maxlength)
	{
		this.GetString("channel_id", buffer, maxlength);
	}
};

typeset DiscordMessageReceivedResponseCallback
{ 
	function void(DiscordBot bot, DiscordChannel channel, DiscordMessage message);
	function void(DiscordBot bot, DiscordChannel channel, DiscordMessage message, any data);
};

typeset DiscordMessageSentResponseCallback
{
	function void(DiscordBot bot, DiscordChannel channel, DiscordMessage message, any data);
}

typeset DiscordMessageDeletedResponseCallback
{
	function void(DiscordBot bot);
	function void(DiscordBot bot, any data);
}

typeset DiscordMessageEditedResponseCallback
{
	function void(DiscordBot bot);
	function void(DiscordBot bot, any data);
}
