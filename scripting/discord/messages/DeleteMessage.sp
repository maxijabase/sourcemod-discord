public int Native_DeleteMessage(Handle plugin, int numParams)
{
    // Get native params
    DiscordBot bot = GetNativeCell(1);
    Function cb = GetNativeCell(2);
    DiscordChannel channel = GetNativeCell(3);
    DiscordMessage message = GetNativeCell(4);
    any data = GetNativeCell(5);

    // Datapack
    DataPack pack = new DataPack();
    pack.WriteCell(bot);
    pack.WriteFunction(cb);
    pack.WriteCell(plugin);
    pack.WriteCell(data);

    // Make URL
    char channelId[32];
    channel.GetID(channelId, sizeof(channelId));
    char url[128];
    Format(url, sizeof(url), "https://discord.com/api/channels/%s/messages", channelId);

    // Create and send request
    DiscordRequest req = new DiscordRequest(url);
    req.SetBot(bot);
    req.Delete(OnMessageDeleted, pack);
}

public void OnMessageDeleted(HTTPResponse response, DataPack pack, const char[] error)
{
    if (response.Status != HTTPStatus_OK)
    {
        LogError("Couldn't Send DeleteMessage - HTTP %i\n%s", response.Status, error);
        delete pack;
        return;
    }

    pack.Reset();
    DiscordBot bot = pack.ReadCell();
    Function cb = pack.ReadFunction();
    Handle plugin = pack.ReadCell();
    any data = pack.ReadCell();
    delete pack;

    Call_StartFunction(plugin, cb);
    Call_PushCell(bot);
    Call_PushCell(data);
    Call_Finish();
}