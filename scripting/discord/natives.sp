void CreateNatives()
{
	CreateNative("DiscordBot.GetToken", Native_DiscordBot_Token_Get);

	// SendMessage.sp
	CreateNative("DiscordBot.SendMessage", Native_DiscordBot_SendMessage);
	CreateNative("DiscordBot.SendMessageToChannelID", Native_DiscordBot_SendMessageToChannel);
	CreateNative("DiscordChannel.SendMessage", Native_DiscordChannel_SendMessage);

	// deletemessage.sp
	CreateNative("DiscordBot.DeleteMessageID", Native_DiscordBot_DeleteMessageID);
	CreateNative("DiscordBot.DeleteMessage", Native_DiscordBot_DeleteMessage);

	// ListenToChannel.sp
	CreateNative("DiscordBot.StartTimer", Native_DiscordBot_StartTimer);

	// GetGuilds.sp
	CreateNative("DiscordBot.GetGuilds", Native_DiscordBot_GetGuilds);
	// GetGuildChannels.sp
	CreateNative("DiscordBot.GetGuildChannels", Native_DiscordBot_GetGuildChannels);
	// GuildRole.sp
	CreateNative("DiscordBot.GetGuildRoles", Native_DiscordBot_GetGuildRoles);

	// reactions.sp
	CreateNative("DiscordBot.AddReactionID", Native_DiscordBot_AddReaction);
	CreateNative("DiscordBot.DeleteReactionID", Native_DiscordBot_DeleteReaction);
	CreateNative("DiscordBot.GetReactionID", Native_DiscordBot_GetReaction);

	// GuildMembers.sp
	CreateNative("DiscordBot.GetGuildMembers", Native_DiscordBot_GetGuildMembers);
	CreateNative("DiscordBot.GetGuildMembersAll", Native_DiscordBot_GetGuildMembersAll);

	// CreateNative("DiscordChannel.Destroy", Native_DiscordChannel_Destroy);

	// SendWebHook.sp
	CreateNative("DiscordWebHook.Send", Native_DiscordWebHook_Send);
	// CreateNative("DiscordWebHook.AddField", Native_DiscordWebHook_AddField);
	// CreateNative("DiscordWebHook.DeleteFields", Native_DiscordWebHook_DeleteFields);

	// UserObject.sp
	CreateNative("DiscordUser.GetID", Native_DiscordUser_GetID);
	CreateNative("DiscordUser.GetUsername", Native_DiscordUser_GetUsername);
	CreateNative("DiscordUser.GetAvatar", Native_DiscordUser_GetAvatar);
	CreateNative("DiscordUser.IsVerified", Native_DiscordUser_IsVerified);
	CreateNative("DiscordUser.GetEmail", Native_DiscordUser_GetEmail);
	CreateNative("DiscordUser.IsBot", Native_DiscordUser_IsBot);

	// MessageObject.sp
	CreateNative("DiscordMessage.GetID", Native_DiscordMessage_GetID);
	CreateNative("DiscordMessage.IsPinned", Native_DiscordMessage_IsPinned);
	CreateNative("DiscordMessage.GetAuthor", Native_DiscordMessage_GetAuthor);
	CreateNative("DiscordMessage.GetContent", Native_DiscordMessage_GetContent);
	CreateNative("DiscordMessage.GetChannelID", Native_DiscordMessage_GetChannelID);
}