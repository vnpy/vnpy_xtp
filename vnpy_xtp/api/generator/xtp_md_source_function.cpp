int MdApi::queryAllTickers(int exchange_id)
{
	int i = this->api->QueryAllTickers(exchange_id);
	return i;
};

int MdApi::queryTickersPriceInfo(char ticker, int count, int exchange_id)
{
	int i = this->api->QueryTickersPriceInfo(ticker, count, exchange_id);
	return i;
};

int MdApi::queryAllTickersPriceInfo()
{
	int i = this->api->QueryAllTickersPriceInfo();
	return i;
};

int MdApi::queryAllTickersFullInfo(int exchange_id)
{
	int i = this->api->QueryAllTickersFullInfo(exchange_id);
	return i;
};

