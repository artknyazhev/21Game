#include "MyForm.h"
#include <Windows.h>
#include <string>
#include <vector>
#include <time.h>
using namespace Project3;
class Card
{
public:
	Card(int v, int m) {
		val = v;
		type = mast[m];
		s_val = to_string(val);
	}
	int GetV() {

		return val;
	}
	string GetT() {
		if (val == 2)
			s_val = "J(" + type + ")";
		else if (val == 3)
			s_val = "Q(" + type + ")";
		else if (val == 4)
			s_val = "K(" + type + ")";
		else if (val == 11)
			s_val = "A(" + type + ")";
		else
			s_val += ('(' + type + ')');
		return s_val;
	}
	~Card() = default;

protected:
	int val;
	string s_val;
	vector<string> mast = { "hearts","spades","diamonds","clubs"};
	string type;
};
vector<Card> c = { Card(6,0),Card(6,1),Card(6,2),Card(6,3),
	Card(7,0),Card(7,1),Card(7,2),Card(7,3),
	Card(8,0),Card(8,1),Card(8,2),Card(8,3),
	Card(9,0),Card(9,1),Card(9,2),Card(9,3),
	Card(10,0),Card(10,1),Card(10,2),Card(10,3),
	Card(2,0),Card(2,1),Card(2,2),Card(2,3),
	Card(3,0),Card(3,1),Card(3,2),Card(3,3),
	Card(4,0),Card(4,1),Card(4,2),Card(4,3),
	Card(11,0),Card(11,1),Card(11,2),Card(11,3) };
class Game 
{
public:
	Game() {}
	void StartGame() {
		srand(time(NULL));
		int rnd = 0 + rand() % c.size();
		player += c[rnd].GetT();
		p_val += c[rnd].GetV();
		c.erase(c.begin() + rnd);
		rnd = 0 + rand() % c.size();
		dealer += c[rnd].GetT();
		d_val += c[rnd].GetV();
		c.erase(c.begin() + rnd);
		player += c[rnd].GetT();
		p_val += c[rnd].GetV();
		c.erase(c.begin() + rnd);
		rnd = 0 + rand() % c.size();
		dealer += c[rnd].GetT();
		d_val += c[rnd].GetV();
		c.erase(c.begin() + rnd);
	}
	~Game()=default;

	int d_val = 0;
	int p_val = 0;
	string dealer = "";
	string player = "";
};

[STAThreadAttribute]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}

Game g;
System::Void Project3::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{

	return System::Void();
}

System::Void Project3::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void Project3::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void Project3::MyForm::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	g.StartGame();
	System::String^ s = gcnew System::String(g.dealer.c_str());
	textBox1->Text = s;
	s = gcnew System::String(g.player.c_str());
	textBox2->Text = s;
	button4->Enabled = false;
	return System::Void();
}
