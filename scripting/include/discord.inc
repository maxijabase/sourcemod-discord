#if defined _discord_included
	#endinput
#endif
#define _discord_included

#include <smjansson>
#include <ripext>

typeset DiscordGuildsResponseCallback
{
	function void(DiscordBot bot, char[] id, char[] name, char[] icon, bool owner, int permissions);
	function void(DiscordBot bot, char[] id, char[] name, char[] icon, bool owner, int permissions, any data);
}

typeset DiscordGuildChannelsResponseCallback
{
	function void (DiscordBot bot, char[] guild, DiscordChannel channel);
	function void (DiscordBot bot, char[] guild, DiscordChannel channel, any data);
}

typeset DiscordGuildRolesResponseCallback
{
	function void (DiscordBot bot, char[] guild, RoleList Roles);
	function void (DiscordBot bot, char[] guild, RoleList Roles, any data);
}

typeset DiscordGuildMembersResponseCallback
{
	function void(DiscordBot bot, char[] guild, JSONArray members);
	function void(DiscordBot bot, char[] guild, JSONArray members, any data);
}

typeset DiscordMessageReceivedResponseCallback
{ 
	function void(DiscordBot bot, DiscordChannel channel, DiscordMessage message);
	function void(DiscordBot bot, DiscordChannel channel, DiscordMessage message, any data);
};

typeset DiscordMessageSentResponseCallback
{
	function void(DiscordBot bot, char[] channel, DiscordMessage message, any data);
}

typeset DiscordMessageDeletedResponseCallback
{
	function void(DiscordBot bot);
	function void(DiscordBot bot, any data);
}

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