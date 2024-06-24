#if defined _discord_included
	#endinput
#endif
#define _discord_included

#include <ripext>

#include "discord/guild/DiscordGuild"
#include "discord/guild/DiscordRole"
#include "discord/guild/DiscordChannel"
#include "discord/guild/DiscordGuildMember"
#include "discord/user/DiscordUser"
#include "discord/webhook/DiscordWebHook"
#include "discord/message/DiscordMessage"
#include "discord/message/MessageEmbed"
#include "discord/bot/DiscordBot"

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

}
#endif