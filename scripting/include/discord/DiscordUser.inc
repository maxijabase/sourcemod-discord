/*
{
    "id": "80351110224678912",
    "username": "Nelly",
    "avatar": "8342729096ea3675442027381ff50dfe",
    "verified": true,
    "email": "nelly@discord.com"
}
 */
//It's a JSON Handle with the above info TODO stop using natives!
methodmap DiscordUser < JSONObject
{
	public native void GetID(char[] buffer, int maxlength);
	
	public native void GetUsername(char[] buffer, int maxlength);
	
	public native void GetAvatar(char[] buffer, int maxlength);
	
	public native bool IsVerified();
	
	public native void GetEmail(char[] buffer, int maxlength);
	
	public native bool IsBot();
};