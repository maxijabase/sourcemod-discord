methodmap DiscordUser < JSONObject
{
	public native void GetID(char[] buffer, int maxlength);
	
	public native void GetUsername(char[] buffer, int maxlength);
	
	public native void GetAvatar(char[] buffer, int maxlength);
	
	public native bool IsVerified();
	
	public native void GetEmail(char[] buffer, int maxlength);
	
	public native bool IsBot();
};