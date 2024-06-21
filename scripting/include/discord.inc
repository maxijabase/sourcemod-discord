#if defined _discord_included
	#endinput
#endif
#define _discord_included

#include <smjansson>
#include <ripext>

typedef DiscordGuildsRetrieve = function void (DiscordBot bot, char[] id, char[] name, char[] icon, bool owner, int permissions, any data);

typedef DiscordGuildsRetrievedAll = function void (DiscordBot bot, ArrayList id, ArrayList name, ArrayList icon, ArrayList owner, ArrayList permissions, any data);

//Channel are Handles that are closed immediately after forwards called. To keep, clone. Or store id if thats what you want
typedef DiscordGuildChannelsRetrieve = function void (DiscordBot bot, char[] guild, DiscordChannel Channel, any data);

typedef DiscordGuildChannelsRetrieveAll = function void (DiscordBot bot, char[] guild, ArrayList Channels, any data);

typedef DiscordGuildGetRoles = function void (DiscordBot bot, char[] guild, RoleList Roles, any data);

/** 
 * Called when message is received
 * bot/channel/message are all destroyed after callback is sent.
 * You can clone it if need to keep.
 */
typeset OnChannelMessage
{ 
	function void(DiscordBot bot, DiscordChannel channel, DiscordMessage message);
};

typedef OnGetReactions = function void (DiscordBot bot, ArrayList Users, char[] channelID, const char[] messageID, const char[] emoji, any data);

typedef OnMessageSent = function void(DiscordBot bot, char[] channel, DiscordMessage message, any data);

typedef OnMessageDeleted = function void(DiscordBot bot, any data);

// hMemberList is JSON array containing guild members
typedef OnGetMembers = function void(DiscordBot bot, char[] guild, Handle hMemberList);

#include "discord/DiscordBot"
#include "discord/DiscordRole"
#include "discord/DiscordUser"
#include "discord/DiscordMessage"
#include "discord/DiscordChannel"
#include "discord/DiscordGuildUser"
#include "discord/DiscordWebHook"
#include "discord/MessageEmbed"

public SharedPlugin __pl_discordapi =
{
	name = "discord-api",
	file = "discord-api.smx",
	#if defined REQUIRE_PLUGIN
	required = 1,
	#else
	required = 0,
	#endif
};

#if !defined REQUIRE_PLUGIN
public void __pl_discordapi_SetNTVOptional()
{
	MarkNativeAsOptional("DiscordUser.GetID");
	MarkNativeAsOptional("DiscordUser.GetUsername");
	MarkNativeAsOptional("DiscordUser.GetAvatar");
	MarkNativeAsOptional("DiscordUser.IsVerified");
	MarkNativeAsOptional("DiscordUser.GetEmail");
	MarkNativeAsOptional("DiscordUser.IsBot");
	MarkNativeAsOptional("DiscordMessage.GetID");
	MarkNativeAsOptional("DiscordMessage.IsPinned");
	MarkNativeAsOptional("DiscordMessage.DiscordUser GetAuthor");
	MarkNativeAsOptional("DiscordMessage.GetContent");
	MarkNativeAsOptional("DiscordMessage.GetChannelID");
	MarkNativeAsOptional("DiscordBot.StartTimer");
	MarkNativeAsOptional("DiscordBot.AddReactionID");
	MarkNativeAsOptional("DiscordBot.DeleteReactionID");
	MarkNativeAsOptional("DiscordBot.GetReactionID");
	MarkNativeAsOptional("DiscordBot.GetToken");
	MarkNativeAsOptional("DiscordBot.SendMessage");
	MarkNativeAsOptional("DiscordBot.SendMessageToChannelID");
	MarkNativeAsOptional("DiscordBot.DeleteMessageID");
	MarkNativeAsOptional("DiscordBot.DeleteMessage");
	MarkNativeAsOptional("DiscordBot.GetGuilds");
	MarkNativeAsOptional("DiscordBot.GetGuildChannels");
	MarkNativeAsOptional("DiscordBot.GetGuildMembers");
	MarkNativeAsOptional("DiscordBot.GetGuildMembersAll");
	MarkNativeAsOptional("DiscordBot.GetGuildRoles");
	MarkNativeAsOptional("DiscordChannel.SendMessage");
	MarkNativeAsOptional("DiscordWebHook.Send");
}
#endif