void CreateNatives()
{
    // Guilds
    CreateNative("DiscordBot.GetGuilds", Native_GetGuilds);
    CreateNative("DiscordBot.GetGuildChannels", Native_GetGuildChannels);
    CreateNative("DiscordBot.GetGuildMembers", Native_GetGuildMembers);
    CreateNative("DiscordBot.GetGuildRoles", Native_GetGuildRoles);
    CreateNative("DiscordBot.GetGuildRoles", Native_GetGuildRoles);
    CreateNative("StartListeningToChannel", Native_StartListeningToChannel);
    
    // Messages
    CreateNative("DiscordBot.SendMessage", Native_SendMessage);
    CreateNative("DiscordBot.EditMessage", Native_EditMessage);
    CreateNative("DiscordBot.DeleteMessage", Native_DeleteMessage);
    
    // WebHooks
    CreateNative("DiscordWebHook.SendWebHook", Native_SendWebHook);
} 