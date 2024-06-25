#pragma semicolon 1
#pragma dynamic 25000

#include <sourcemod>
#include <steamworks>
#include <updater>
#include <smjansson>
#include <ripext>

#include "include/discord"
#include "discord/guilds/GetGuilds.sp"
#include "discord/guilds/GetGuildChannels.sp"
#include "discord/guilds/ListenToChannel.sp"
#include "discord/guilds/GetGuildMembers.sp"
#include "discord/guilds/GetGuildRoles.sp"
#include "discord/messages/SendMessage.sp"
#include "discord/messages/EditMessage.sp"
#include "discord/messages/DeleteMessage.sp"
#include "discord/webhooks/SendWebHook.sp"
#include "discord/Natives.sp"
#include "discord/DiscordRequest.sp"

#define UPDATE_URL "https://raw.githubusercontent.com/maxijabase/sourcemod-discord/master/updatefile.txt"

public Plugin myinfo = {
    name = "[API] Discord API", 
    author = "Deathknife (ampere version)", 
    description = "API to interact with Discord", 
    version = "1.0", 
    url = "github.com/maxijabase/sourcemod-discord"
};

public APLRes AskPluginLoad2(Handle myself, bool late, char[] error, int err_max)
{
    CreateNatives();
    RegPluginLibrary("discord-api");
    return APLRes_Success;
}

public void OnPluginStart()
{
    if (LibraryExists("updater"))
    {
        Updater_AddPlugin(UPDATE_URL);
    }
}

public void OnLibraryAdded(const char[] name)
{
    if (StrEqual(name, "updater"))
    {
        Updater_AddPlugin(UPDATE_URL);
    }
} 