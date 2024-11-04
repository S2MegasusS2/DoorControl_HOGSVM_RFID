#pragma once
#include "Windows.h"
#include "Register_UI.h"
#include "Room1_UI.h"
#include "deleteUser_UI.h"

#define originalFormWidth 1280
#define originalFormHeight 960

namespace ESP32Interface {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ESP32_Main_Menu
	/// </summary>
	public ref class ESP32_Main_Menu : public System::Windows::Forms::Form
	{
	public:
		ESP32_Main_Menu(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			
			// Initialize the timer
			timer = gcnew System::Windows::Forms::Timer();
			// Set the interval for the timer (e.g., update every second)
			timer->Interval = 1000;
			// Add the event handler for the timer tick event
			timer->Tick += gcnew System::EventHandler(this, &ESP32_Main_Menu::Timer_Update);
			// Start the timer
			timer->Start();
		}
		ESP32_Main_Menu(System::String^ data)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ESP32_Main_Menu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ exit_Button;

	private: System::Windows::Forms::Label^ time_Label;
	private: System::Windows::Forms::Button^ register_Button;

	private: System::Windows::Forms::Label^ ESP32_connect_status_Label;
	private: System::Windows::Forms::Button^ open_RoomInfo_Button;

	private: System::Windows::Forms::Panel^ choose_listRoom_Panel;

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ exit_get_img_Button;
	private: System::Windows::Forms::Button^ delete_user_Button;
	private: System::Windows::Forms::Button^ show_Room1Info_Button;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button2;



	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

	protected:
		///<summary>
		/// Overrides the default WndProc method to enable resizing of the form using the mouse or dragging app.
		/// </summary>
		/// <param name="m">A Windows Message object: 0x84</param>
		void WndProc(Message% m) override {
		switch (m.Msg)
		{
		case WM_NCHITTEST: {
			// WM_NCHITTEST
			// Enable resizing when the mouse is on the form border
			System::Drawing::Point pos = System::Drawing::Point(m.LParam.ToInt32());
			pos = this->PointToClient(pos);
			if (pos.X <= 5) {
				if (pos.Y <= 5)
					m.Result = IntPtr(13); // HTTOPLEFT
				else if (pos.Y >= ClientSize.Height - 5)
					m.Result = IntPtr(16); // HTBOTTOMLEFT
				else
					m.Result = IntPtr(10); // HTLEFT
			}
			else if (pos.X >= ClientSize.Width - 5) {
				if (pos.Y <= 5)
					m.Result = IntPtr(14); // HTTOPRIGHT
				else if (pos.Y >= ClientSize.Height - 5)
					m.Result = IntPtr(17); // HTBOTTOMRIGHT
				else
					m.Result = IntPtr(11); // HTRIGHT
			}
			else if (pos.Y <= 5)
				m.Result = IntPtr(12); // HTTOP
			else if (pos.Y >= ClientSize.Height - 5)
				m.Result = IntPtr(15); // HTBOTTOM
			else {
				// Enable dragging app
				m.Result = IntPtr(HT_CAPTION);
			}
			break;
		}
		default: Form::WndProc(m);
		}
	}
	private:
	/// <summary>
	/// Required designer variable.
	/// </summary>
	const int HT_CLIENT = 0x1;
	const int HT_CAPTION = 0x2;

	private:
	/// <summary>
	/// Create Instance of Multiple UI
	/// </summary>

	// Create Instance of Register_UI;
	Register_UI^ registerForm = gcnew Register_UI();
	Room1_UI^ room1_UI = gcnew Room1_UI();
	deleteUser_UI^ DeleteUser_UI = gcnew deleteUser_UI();
	private: System::Windows::Forms::Timer^ timer;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ESP32_Main_Menu::typeid));
			this->exit_Button = (gcnew System::Windows::Forms::Button());
			this->time_Label = (gcnew System::Windows::Forms::Label());
			this->register_Button = (gcnew System::Windows::Forms::Button());
			this->ESP32_connect_status_Label = (gcnew System::Windows::Forms::Label());
			this->open_RoomInfo_Button = (gcnew System::Windows::Forms::Button());
			this->choose_listRoom_Panel = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->exit_get_img_Button = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->show_Room1Info_Button = (gcnew System::Windows::Forms::Button());
			this->delete_user_Button = (gcnew System::Windows::Forms::Button());
			this->choose_listRoom_Panel->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// exit_Button
			// 
			this->exit_Button->BackColor = System::Drawing::Color::Black;
			this->exit_Button->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->exit_Button->FlatAppearance->BorderSize = 2;
			this->exit_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exit_Button->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20));
			this->exit_Button->ForeColor = System::Drawing::Color::White;
			this->exit_Button->Location = System::Drawing::Point(108, 855);
			this->exit_Button->Name = L"exit_Button";
			this->exit_Button->Size = System::Drawing::Size(137, 54);
			this->exit_Button->TabIndex = 11;
			this->exit_Button->TabStop = false;
			this->exit_Button->Text = L"Exit";
			this->exit_Button->UseVisualStyleBackColor = false;
			this->exit_Button->Click += gcnew System::EventHandler(this, &ESP32_Main_Menu::exit_Button_Click);
			// 
			// time_Label
			// 
			this->time_Label->AutoSize = true;
			this->time_Label->BackColor = System::Drawing::SystemColors::Desktop;
			this->time_Label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 30));
			this->time_Label->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->time_Label->Location = System::Drawing::Point(587, 42);
			this->time_Label->Name = L"time_Label";
			this->time_Label->Size = System::Drawing::Size(246, 54);
			this->time_Label->TabIndex = 13;
			this->time_Label->Text = L"Time_Holder";
			// 
			// register_Button
			// 
			this->register_Button->BackColor = System::Drawing::Color::Navy;
			this->register_Button->FlatAppearance->BorderColor = System::Drawing::Color::Blue;
			this->register_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->register_Button->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16));
			this->register_Button->ForeColor = System::Drawing::Color::White;
			this->register_Button->Location = System::Drawing::Point(1283, 250);
			this->register_Button->Name = L"register_Button";
			this->register_Button->Size = System::Drawing::Size(185, 50);
			this->register_Button->TabIndex = 14;
			this->register_Button->TabStop = false;
			this->register_Button->Text = L"Register Room";
			this->register_Button->UseVisualStyleBackColor = false;
			this->register_Button->Click += gcnew System::EventHandler(this, &ESP32_Main_Menu::register_Button_Click);
			// 
			// ESP32_connect_status_Label
			// 
			this->ESP32_connect_status_Label->AutoSize = true;
			this->ESP32_connect_status_Label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->ESP32_connect_status_Label->ForeColor = System::Drawing::Color::Red;
			this->ESP32_connect_status_Label->Location = System::Drawing::Point(1242, 215);
			this->ESP32_connect_status_Label->Name = L"ESP32_connect_status_Label";
			this->ESP32_connect_status_Label->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->ESP32_connect_status_Label->Size = System::Drawing::Size(0, 19);
			this->ESP32_connect_status_Label->TabIndex = 15;
			this->ESP32_connect_status_Label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// open_RoomInfo_Button
			// 
			this->open_RoomInfo_Button->BackColor = System::Drawing::Color::Navy;
			this->open_RoomInfo_Button->FlatAppearance->BorderColor = System::Drawing::Color::Blue;
			this->open_RoomInfo_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->open_RoomInfo_Button->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16));
			this->open_RoomInfo_Button->ForeColor = System::Drawing::Color::White;
			this->open_RoomInfo_Button->Location = System::Drawing::Point(1283, 332);
			this->open_RoomInfo_Button->Name = L"open_RoomInfo_Button";
			this->open_RoomInfo_Button->Size = System::Drawing::Size(185, 50);
			this->open_RoomInfo_Button->TabIndex = 16;
			this->open_RoomInfo_Button->TabStop = false;
			this->open_RoomInfo_Button->Text = L"Room Info";
			this->open_RoomInfo_Button->UseVisualStyleBackColor = false;
			this->open_RoomInfo_Button->Click += gcnew System::EventHandler(this, &ESP32_Main_Menu::open_RoomInfo_Button_Click);
			// 
			// choose_listRoom_Panel
			// 
			this->choose_listRoom_Panel->Controls->Add(this->label2);
			this->choose_listRoom_Panel->Controls->Add(this->exit_get_img_Button);
			this->choose_listRoom_Panel->Controls->Add(this->panel2);
			this->choose_listRoom_Panel->Location = System::Drawing::Point(79, 119);
			this->choose_listRoom_Panel->Name = L"choose_listRoom_Panel";
			this->choose_listRoom_Panel->Size = System::Drawing::Size(1431, 790);
			this->choose_listRoom_Panel->TabIndex = 17;
			this->choose_listRoom_Panel->Visible = false;
			this->choose_listRoom_Panel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &ESP32_Main_Menu::panel1_Paint);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(651, 38);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(199, 45);
			this->label2->TabIndex = 14;
			this->label2->Text = L"List of Room";
			// 
			// exit_get_img_Button
			// 
			this->exit_get_img_Button->BackColor = System::Drawing::Color::Black;
			this->exit_get_img_Button->ForeColor = System::Drawing::Color::White;
			this->exit_get_img_Button->Location = System::Drawing::Point(680, 697);
			this->exit_get_img_Button->Name = L"exit_get_img_Button";
			this->exit_get_img_Button->Size = System::Drawing::Size(100, 45);
			this->exit_get_img_Button->TabIndex = 12;
			this->exit_get_img_Button->Text = L"Exit";
			this->exit_get_img_Button->UseVisualStyleBackColor = false;
			this->exit_get_img_Button->Click += gcnew System::EventHandler(this, &ESP32_Main_Menu::exit_get_img_Button_Click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->button2);
			this->panel2->Controls->Add(this->show_Room1Info_Button);
			this->panel2->Location = System::Drawing::Point(79, 118);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1291, 535);
			this->panel2->TabIndex = 0;
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24));
			this->button2->Location = System::Drawing::Point(347, 24);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(286, 160);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Coming Soon";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// show_Room1Info_Button
			// 
			this->show_Room1Info_Button->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24));
			this->show_Room1Info_Button->Location = System::Drawing::Point(36, 24);
			this->show_Room1Info_Button->Name = L"show_Room1Info_Button";
			this->show_Room1Info_Button->Size = System::Drawing::Size(286, 160);
			this->show_Room1Info_Button->TabIndex = 0;
			this->show_Room1Info_Button->Text = L"Room 1";
			this->show_Room1Info_Button->UseVisualStyleBackColor = true;
			this->show_Room1Info_Button->Click += gcnew System::EventHandler(this, &ESP32_Main_Menu::show_Room1Info_Button_Click);
			// 
			// delete_user_Button
			// 
			this->delete_user_Button->BackColor = System::Drawing::Color::Navy;
			this->delete_user_Button->FlatAppearance->BorderColor = System::Drawing::Color::Blue;
			this->delete_user_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->delete_user_Button->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16));
			this->delete_user_Button->ForeColor = System::Drawing::Color::White;
			this->delete_user_Button->Location = System::Drawing::Point(1283, 421);
			this->delete_user_Button->Name = L"delete_user_Button";
			this->delete_user_Button->Size = System::Drawing::Size(185, 50);
			this->delete_user_Button->TabIndex = 18;
			this->delete_user_Button->TabStop = false;
			this->delete_user_Button->Text = L"Delete User";
			this->delete_user_Button->UseVisualStyleBackColor = false;
			this->delete_user_Button->Click += gcnew System::EventHandler(this, &ESP32_Main_Menu::delete_user_Button_Click);
			// 
			// ESP32_Main_Menu
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1600, 1024);
			this->Controls->Add(this->choose_listRoom_Panel);
			this->Controls->Add(this->open_RoomInfo_Button);
			this->Controls->Add(this->ESP32_connect_status_Label);
			this->Controls->Add(this->register_Button);
			this->Controls->Add(this->time_Label);
			this->Controls->Add(this->exit_Button);
			this->Controls->Add(this->delete_user_Button);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"ESP32_Main_Menu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ESP32_Main_Menu";
			this->Load += gcnew System::EventHandler(this, &ESP32_Main_Menu::ESP32_Main_Menu_Load);
			this->choose_listRoom_Panel->ResumeLayout(false);
			this->choose_listRoom_Panel->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
#pragma region user function code

#pragma region disAllButt
	private: System::Void disableAllButt() {
		register_Button->Enabled = FALSE;
		open_RoomInfo_Button->Enabled = FALSE;
		delete_user_Button->Enabled = FALSE;
		exit_Button->Enabled = FALSE;
	}
#pragma endregion

#pragma region enAllButt
	private: System::Void enAllButt() {
		register_Button->Enabled = TRUE;
		open_RoomInfo_Button->Enabled = TRUE;
		delete_user_Button->Enabled = TRUE;
		exit_Button->Enabled = TRUE;
	}
#pragma endregion

#pragma region exit_Button
	private: System::Void exit_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
#pragma endregion

#pragma region Timer_Update
	private: System::Void Timer_Update(System::Object^ sender, System::EventArgs^ e) {
		// Get the current time
		System::DateTime currentTime = System::DateTime::Now;

		// Update the label text with the current time
		time_Label->Text = currentTime.ToString();
	}
#pragma endregion

#pragma region ESP32_Main_Meun_Load
	private: System::Void ESP32_Main_Menu_Load(System::Object^ sender, System::EventArgs^ e) {
		// Call the event handler once to update the time_Label immediately
		Timer_Update(nullptr, nullptr);
	}
#pragma endregion

#pragma region openRegisterUI
	
	private: System::Void register_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		// Create an instance of the Register_UI form

		// Show the Register_UI form
		registerForm->Show();
	}

#pragma endregion


private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void exit_get_img_Button_Click(System::Object^ sender, System::EventArgs^ e) {
	choose_listRoom_Panel->Visible = FALSE;
}
private: System::Void open_RoomInfo_Button_Click(System::Object^ sender, System::EventArgs^ e) {
	choose_listRoom_Panel->Visible = TRUE;

}
private: System::Void delete_user_Button_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteUser_UI->Show();
}

private: System::Void show_Room1Info_Button_Click(System::Object^ sender, System::EventArgs^ e) {
	choose_listRoom_Panel->Visible = FALSE;
	room1_UI->Show();
}
};
#pragma endregion
}
