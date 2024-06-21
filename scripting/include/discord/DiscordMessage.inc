methodmap DiscordMessage < JSONObject
{
	public native void GetID(char[] buffer, int maxlength);
	
	public native bool IsPinned();
	
	public native DiscordUser GetAuthor();
	
	public native void GetContent(char[] buffer, int maxlength);
	
	public native void GetChannelID(char[] buffer, int maxlength);
};
