#pragma once
#include "Windows.h"
#include "ESP32_Main_Menu.h"
namespace ESP32Interface {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ESP32_Login_UI
	/// </summary>
	public ref class ESP32_Login_UI : public System::Windows::Forms::Form
	{
	public:
		ESP32_Login_UI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here

			// Hide Terms and Conditions panel
			terms_Panel->Hide();
			// Remove border
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;

			// Enable resizing with mouse
			this->SetStyle(System::Windows::Forms::ControlStyles::ResizeRedraw, true);
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Show;

			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ESP32_Login_UI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ welcome_Label;
	private: System::Windows::Forms::Label^ username_Label;
	private: System::Windows::Forms::Label^ password_Label;
	private: System::Windows::Forms::TextBox^ username_textBox;
	private: System::Windows::Forms::TextBox^ password_textBox;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::CheckBox^ agree_terms_checkBox;

	private: System::Windows::Forms::Label^ terms_link_Label;
	private: System::Windows::Forms::Button^ sign_in_Button;
	private: System::Windows::Forms::Button^ exit_Button;

	private: System::Windows::Forms::Label^ failed_sign_in_Label;
	private: System::Windows::Forms::Panel^ terms_Panel;
	private: System::Windows::Forms::Label^ terms_UI_Text;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ agree_terms_Button;





	protected:

	protected:

	protected:









	private: System::ComponentModel::IContainer^ components;









	protected:


	protected:

	protected:
		/// <summary>
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

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ESP32_Login_UI::typeid));
			this->welcome_Label = (gcnew System::Windows::Forms::Label());
			this->username_Label = (gcnew System::Windows::Forms::Label());
			this->password_Label = (gcnew System::Windows::Forms::Label());
			this->username_textBox = (gcnew System::Windows::Forms::TextBox());
			this->password_textBox = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->agree_terms_checkBox = (gcnew System::Windows::Forms::CheckBox());
			this->terms_link_Label = (gcnew System::Windows::Forms::Label());
			this->sign_in_Button = (gcnew System::Windows::Forms::Button());
			this->exit_Button = (gcnew System::Windows::Forms::Button());
			this->failed_sign_in_Label = (gcnew System::Windows::Forms::Label());
			this->terms_Panel = (gcnew System::Windows::Forms::Panel());
			this->agree_terms_Button = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->terms_UI_Text = (gcnew System::Windows::Forms::Label());
			this->terms_Panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// welcome_Label
			// 
			this->welcome_Label->AutoSize = true;
			this->welcome_Label->BackColor = System::Drawing::SystemColors::Desktop;
			this->welcome_Label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24));
			this->welcome_Label->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->welcome_Label->Location = System::Drawing::Point(61, 161);
			this->welcome_Label->Name = L"welcome_Label";
			this->welcome_Label->Size = System::Drawing::Size(551, 45);
			this->welcome_Label->TabIndex = 0;
			this->welcome_Label->Text = L"Welcome to Room Management App";
			// 
			// username_Label
			// 
			this->username_Label->AutoSize = true;
			this->username_Label->BackColor = System::Drawing::SystemColors::Desktop;
			this->username_Label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16));
			this->username_Label->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->username_Label->Location = System::Drawing::Point(64, 257);
			this->username_Label->Name = L"username_Label";
			this->username_Label->Size = System::Drawing::Size(111, 30);
			this->username_Label->TabIndex = 1;
			this->username_Label->Text = L"Username";
			// 
			// password_Label
			// 
			this->password_Label->AutoSize = true;
			this->password_Label->BackColor = System::Drawing::SystemColors::Desktop;
			this->password_Label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16));
			this->password_Label->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->password_Label->Location = System::Drawing::Point(64, 346);
			this->password_Label->Name = L"password_Label";
			this->password_Label->Size = System::Drawing::Size(103, 30);
			this->password_Label->TabIndex = 2;
			this->password_Label->Text = L"Password";
			// 
			// username_textBox
			// 
			this->username_textBox->BackColor = System::Drawing::Color::Black;
			this->username_textBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->username_textBox->ForeColor = System::Drawing::Color::White;
			this->username_textBox->Location = System::Drawing::Point(69, 290);
			this->username_textBox->Name = L"username_textBox";
			this->username_textBox->Size = System::Drawing::Size(333, 29);
			this->username_textBox->TabIndex = 3;
			this->username_textBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &ESP32_Login_UI::username_textBox_KeyDown);
			// 
			// password_textBox
			// 
			this->password_textBox->BackColor = System::Drawing::Color::Black;
			this->password_textBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->password_textBox->ForeColor = System::Drawing::Color::White;
			this->password_textBox->Location = System::Drawing::Point(69, 386);
			this->password_textBox->Name = L"password_textBox";
			this->password_textBox->Size = System::Drawing::Size(333, 29);
			this->password_textBox->TabIndex = 4;
			this->password_textBox->UseSystemPasswordChar = true;
			this->password_textBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &ESP32_Login_UI::password_textBox_KeyDown);
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(69, 324);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(333, 4);
			this->panel1->TabIndex = 5;
			// 
			// panel2
			// 
			this->panel2->Location = System::Drawing::Point(69, 414);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(333, 4);
			this->panel2->TabIndex = 6;
			// 
			// agree_terms_checkBox
			// 
			this->agree_terms_checkBox->AutoSize = true;
			this->agree_terms_checkBox->BackColor = System::Drawing::Color::Black;
			this->agree_terms_checkBox->Checked = true;
			this->agree_terms_checkBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->agree_terms_checkBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->agree_terms_checkBox->ForeColor = System::Drawing::Color::White;
			this->agree_terms_checkBox->Location = System::Drawing::Point(69, 425);
			this->agree_terms_checkBox->Name = L"agree_terms_checkBox";
			this->agree_terms_checkBox->Size = System::Drawing::Size(111, 23);
			this->agree_terms_checkBox->TabIndex = 7;
			this->agree_terms_checkBox->TabStop = false;
			this->agree_terms_checkBox->Text = L"I agree to the";
			this->agree_terms_checkBox->UseVisualStyleBackColor = false;
			this->agree_terms_checkBox->CheckedChanged += gcnew System::EventHandler(this, &ESP32_Login_UI::agree_terms_checkBox_CheckedChanged);
			// 
			// terms_link_Label
			// 
			this->terms_link_Label->AutoSize = true;
			this->terms_link_Label->BackColor = System::Drawing::SystemColors::Desktop;
			this->terms_link_Label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->terms_link_Label->ForeColor = System::Drawing::Color::CornflowerBlue;
			this->terms_link_Label->Location = System::Drawing::Point(173, 427);
			this->terms_link_Label->Name = L"terms_link_Label";
			this->terms_link_Label->Size = System::Drawing::Size(142, 19);
			this->terms_link_Label->TabIndex = 8;
			this->terms_link_Label->Text = L"Terms and Conditions";
			this->terms_link_Label->Click += gcnew System::EventHandler(this, &ESP32_Login_UI::terms_link_Label_Click);
			this->terms_link_Label->MouseEnter += gcnew System::EventHandler(this, &ESP32_Login_UI::terms_link_Label_MouseEnter);
			this->terms_link_Label->MouseLeave += gcnew System::EventHandler(this, &ESP32_Login_UI::terms_link_Label_MouseLeave);
			// 
			// sign_in_Button
			// 
			this->sign_in_Button->BackColor = System::Drawing::Color::Blue;
			this->sign_in_Button->FlatAppearance->BorderSize = 0;
			this->sign_in_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->sign_in_Button->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->sign_in_Button->Location = System::Drawing::Point(69, 463);
			this->sign_in_Button->Name = L"sign_in_Button";
			this->sign_in_Button->Size = System::Drawing::Size(106, 37);
			this->sign_in_Button->TabIndex = 9;
			this->sign_in_Button->TabStop = false;
			this->sign_in_Button->Text = L"Sign in";
			this->sign_in_Button->UseVisualStyleBackColor = false;
			this->sign_in_Button->Click += gcnew System::EventHandler(this, &ESP32_Login_UI::sign_in_Button_Click);
			// 
			// exit_Button
			// 
			this->exit_Button->BackColor = System::Drawing::Color::Black;
			this->exit_Button->FlatAppearance->BorderColor = System::Drawing::Color::Blue;
			this->exit_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exit_Button->ForeColor = System::Drawing::Color::Blue;
			this->exit_Button->Location = System::Drawing::Point(191, 463);
			this->exit_Button->Name = L"exit_Button";
			this->exit_Button->Size = System::Drawing::Size(106, 37);
			this->exit_Button->TabIndex = 10;
			this->exit_Button->TabStop = false;
			this->exit_Button->Text = L"Exit";
			this->exit_Button->UseVisualStyleBackColor = false;
			this->exit_Button->Click += gcnew System::EventHandler(this, &ESP32_Login_UI::button1_Click);
			// 
			// failed_sign_in_Label
			// 
			this->failed_sign_in_Label->AutoSize = true;
			this->failed_sign_in_Label->BackColor = System::Drawing::Color::Black;
			this->failed_sign_in_Label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->failed_sign_in_Label->ForeColor = System::Drawing::Color::Red;
			this->failed_sign_in_Label->Location = System::Drawing::Point(64, 519);
			this->failed_sign_in_Label->Name = L"failed_sign_in_Label";
			this->failed_sign_in_Label->Size = System::Drawing::Size(357, 19);
			this->failed_sign_in_Label->TabIndex = 11;
			this->failed_sign_in_Label->Text = L"                                                                                 "
				L"      ";
			this->failed_sign_in_Label->Visible = false;
			// 
			// terms_Panel
			// 
			this->terms_Panel->BackColor = System::Drawing::Color::Black;
			this->terms_Panel->Controls->Add(this->agree_terms_Button);
			this->terms_Panel->Controls->Add(this->textBox1);
			this->terms_Panel->Controls->Add(this->terms_UI_Text);
			this->terms_Panel->Location = System::Drawing::Point(205, 76);
			this->terms_Panel->Name = L"terms_Panel";
			this->terms_Panel->Size = System::Drawing::Size(893, 506);
			this->terms_Panel->TabIndex = 12;
			this->terms_Panel->Visible = false;
			this->terms_Panel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &ESP32_Login_UI::terms_Panel_Paint);
			// 
			// agree_terms_Button
			// 
			this->agree_terms_Button->BackColor = System::Drawing::Color::Blue;
			this->agree_terms_Button->FlatAppearance->BorderSize = 0;
			this->agree_terms_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->agree_terms_Button->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->agree_terms_Button->Location = System::Drawing::Point(383, 430);
			this->agree_terms_Button->Name = L"agree_terms_Button";
			this->agree_terms_Button->Size = System::Drawing::Size(106, 37);
			this->agree_terms_Button->TabIndex = 10;
			this->agree_terms_Button->TabStop = false;
			this->agree_terms_Button->Text = L"OK";
			this->agree_terms_Button->UseVisualStyleBackColor = false;
			this->agree_terms_Button->Click += gcnew System::EventHandler(this, &ESP32_Login_UI::agree_terms_Button_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Black;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->ForeColor = System::Drawing::Color::White;
			this->textBox1->Location = System::Drawing::Point(69, 116);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(750, 286);
			this->textBox1->TabIndex = 2;
			this->textBox1->TabStop = false;
			this->textBox1->Text = L"    This is my ESP32 Application. Hope you enjoy using it :>\r\n";
			// 
			// terms_UI_Text
			// 
			this->terms_UI_Text->AutoSize = true;
			this->terms_UI_Text->BackColor = System::Drawing::SystemColors::Desktop;
			this->terms_UI_Text->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24));
			this->terms_UI_Text->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->terms_UI_Text->Location = System::Drawing::Point(62, 40);
			this->terms_UI_Text->Name = L"terms_UI_Text";
			this->terms_UI_Text->Size = System::Drawing::Size(329, 45);
			this->terms_UI_Text->TabIndex = 1;
			this->terms_UI_Text->Text = L"Terms and Conditions";
			// 
			// ESP32_Login_UI
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::SystemColors::ControlLight;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1280, 960);
			this->Controls->Add(this->terms_Panel);
			this->Controls->Add(this->failed_sign_in_Label);
			this->Controls->Add(this->exit_Button);
			this->Controls->Add(this->sign_in_Button);
			this->Controls->Add(this->terms_link_Label);
			this->Controls->Add(this->agree_terms_checkBox);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->password_textBox);
			this->Controls->Add(this->username_textBox);
			this->Controls->Add(this->password_Label);
			this->Controls->Add(this->username_Label);
			this->Controls->Add(this->welcome_Label);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"ESP32_Login_UI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &ESP32_Login_UI::ESP32_Login_UI_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &ESP32_Login_UI::ESP32_Login_UI_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &ESP32_Login_UI::ESP32_Login_UI_MouseUp);
			this->terms_Panel->ResumeLayout(false);
			this->terms_Panel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	//
	// Private user variables
	//
	private: System::String^ adminUserName = "Phat";
	private: System::String^ adminUserPass = "1";
	private: bool user_acc_text_FirstClick = true;
	private: bool user_pass_text_FirstClick = true;

	private: bool isDragging;
	System::Drawing::Point lastCursorPosition;
	//
    //
	//
#pragma region user function
private: System::Void agree_terms_checkBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (agree_terms_checkBox->Checked)
	{
		sign_in_Button->Enabled = true;
	}
	else
	{
		sign_in_Button->Enabled = false;
	}
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}

private: System::Void sign_in_Button_Click(System::Object^ sender, System::EventArgs^ e) {
	if (username_textBox->Text == adminUserName)
	{
		if (password_textBox->Text == "1")
		{
			//MessageBox::Show("Access granted", "Sign in Successful!", MessageBoxButtons::OK, MessageBoxIcon::Information);;
			//Application::Exit();
			ESP32_Main_Menu^ ESP32_MainMenu = gcnew ESP32_Main_Menu;
			System::Threading::Thread::Sleep(1000);
			this->Hide();
			System::Threading::Thread::Sleep(3000);
			ESP32_MainMenu->Show();
		}
		else
		{
			failed_sign_in_Label->Text = "Incorrect username or password";
			failed_sign_in_Label->Visible = true;
		}
	}
	else 
	{
		failed_sign_in_Label->Text = "Incorrect username or password";
		failed_sign_in_Label->Visible = true;
	}
}
private: System::Void terms_Panel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void agree_terms_Button_Click(System::Object^ sender, System::EventArgs^ e) {
	terms_Panel->Hide();
	EnableControls();
}
private: System::Void terms_link_Label_Click(System::Object^ sender, System::EventArgs^ e) {
	terms_Panel->Show();
	DisableControls();
	
}
private: System::Void terms_link_Label_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	// Mouse enter event handler for the terms link label
	terms_link_Label->Font = gcnew System::Drawing::Font(terms_link_Label->Font->FontFamily, terms_link_Label->Font->SizeInPoints, System::Drawing::FontStyle::Underline);
}

private: System::Void terms_link_Label_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	// Mouse leave event handler for the terms link label
	terms_link_Label->Font = gcnew System::Drawing::Font(terms_link_Label->Font->FontFamily, terms_link_Label->Font->SizeInPoints, System::Drawing::FontStyle::Regular);
}
#pragma endregion

#pragma region user outsource function
private: System::Void DisableControls() {
	// Disable controls on when terms and condition panels opening
	username_textBox->Enabled = false;
	password_textBox->Enabled = false;
	exit_Button->Enabled = false;
	sign_in_Button->Enabled = false;
}

private: System::Void EnableControls() {
	// Enable controls on when terms and condition panels opening
	username_textBox->Enabled = true;
	password_textBox->Enabled = true;
	exit_Button->Enabled = true;
	agree_terms_checkBox_CheckedChanged(nullptr, nullptr);
}

private: System::Boolean IsTextBoxEmpty(TextBox^ textBox) {
	return (textBox->Text->Length == 0);
}
#pragma endregion

/// <summary>
/// Enable dragging and get mouse position
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns></returns>
private: System::Void ESP32_Login_UI_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	isDragging = true;
	lastCursorPosition = e->Location;
}
/// <summary>
/// Check whether application able to move
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns></returns>
private: System::Void ESP32_Login_UI_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

}
/// <summary>
/// Disable dragging
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns></returns>
private: System::Void ESP32_Login_UI_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	isDragging = false;
}
private: System::Void username_textBox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyValue == (int)Keys::Enter)
	{
		password_textBox->Focus();
	}
}

private: System::Void password_textBox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyValue == (int)Keys::Enter)
	{
		sign_in_Button->PerformClick();
	}
}

};
}
