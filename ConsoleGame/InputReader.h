#pragma once

#include <set>
#include <future>

enum ButtonKey {
	a = 97,
	d = 100,
	s = 115,
	w = 119,
	SPACE = 329
};

class InputReader
{
public:
	InputReader(InputReader&) = delete;
	void operator=(const InputReader&) = delete;
	bool IsButtonDown(int button) const;
	void CleanBuffer();
	void Start();
	void Stop();

	static InputReader* GetInstance()
	{
		static InputReader* instance;
		if (instance == nullptr) {
			instance = new InputReader();
		}
		return instance;
	}

private:
	std::set<int> buttons;
	std::shared_future<void> read_future;
	bool is_work = false;
	InputReader() {};
	void Read();
};
