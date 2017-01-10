/* 2017.01.09 18:52
 * P_464
 *
 * string and set<Folder*> can be copied simply;
 * using copy-swap you have to construct and destruct another 'Message' additionally;
 */
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Message;
class Folder {
	public:
		void addMsg(Message*);
		void remMsg(Message*);
	private:
		set<Message*> mesgs;
};
void Folder::addMsg(Message *m)
{
	mesgs.insert(m);
}
void Folder::remMsg(Message *m)
{
	mesgs.erase(m);
}

class Message {
	public:
		Message(const string &s = string());
		Message(const Message&);
		Message& operator=(const Message);
		~Message();
		void swap(Message&);
		void save(Folder&);
		void remove(Folder&);
	private:
		string content;
		set<Folder*> folders;
		void add_to_folders(const Message&);
		void remove_from_folders();
};
void Message::save(Folder &folder)
{
	folder.addMsg(this);
	folders.insert(&folder);
}
void Message::remove(Folder &folder)
{
	folder.remMsg(this);
	folders.erase(&folder);
}
void Message::add_to_folders(const Message &m)
{
	for (auto &folder : m.folders)
		folder->addMsg(this);
}
void Message::remove_from_folders()
{
	for (auto &folder : folders)
		folder->remMsg(this);
}
void Message::swap(Message &m)
{
	using std::swap;
	swap(content, m.content);
	swap(folders, m.folders);
	for (auto &folder : folders) {
		folder->remMsg(this);
		folder->addMsg(&m);
	}
	for (auto &folder : m.folders) {
		folder->remMsg(&m);
		folder->addMsg(this);
	}
}
void swap(Message &ma, Message &mb)
{
	ma.swap(mb);
}
Message::Message(const string &s): content(s)
{
}
Message::Message(const Message &m): content(m.content)
{
	add_to_folders(m);
}
Message& Message::operator=(Message m)
{
	using std::swap;
	remove_from_folders();
	swap(*this, m);
	for (auto &folder : folders)
		folder->addMsg(this);
	return *this;
}
Message::~Message()
{
	remove_from_folders();
}


int main(int argc, char **argv)
{

	return 0;
}

