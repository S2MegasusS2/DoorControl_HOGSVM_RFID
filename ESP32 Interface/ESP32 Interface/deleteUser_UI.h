#pragma once

namespace ESP32Interface {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for deleteUser_UI
	/// </summary>
	public ref class deleteUser_UI : public System::Windows::Forms::Form
	{
	public:
		deleteUser_UI(void)
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
		~deleteUser_UI()
		{
			if (components)
			{
				delete components;
			}
		}

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

	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Button^ exit_Button;
	private: System::Windows::Forms::Button^ delete_User_Button;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ userID_textBox;
	private: System::Windows::Forms::Label^ userID_Label;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::TextBox^ username_textBox;
	private: System::Windows::Forms::Label^ username_Label;
	private: System::Windows::Forms::Button^ resetRFID_Button;
	private: System::Windows::Forms::Label^ test_Label;
	private: System::Windows::Forms::Label^ deleteUser_Button;
	private: System::Windows::Forms::Label^ deleteUser_Label;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->username_textBox = (gcnew System::Windows::Forms::TextBox());
			this->username_Label = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->userID_textBox = (gcnew System::Windows::Forms::TextBox());
			this->userID_Label = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->exit_Button = (gcnew System::Windows::Forms::Button());
			this->delete_User_Button = (gcnew System::Windows::Forms::Button());
			this->resetRFID_Button = (gcnew System::Windows::Forms::Button());
			this->test_Label = (gcnew System::Windows::Forms::Label());
			this->deleteUser_Button = (gcnew System::Windows::Forms::Label());
			this->deleteUser_Label = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->username_textBox);
			this->panel1->Controls->Add(this->username_Label);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->userID_textBox);
			this->panel1->Controls->Add(this->userID_Label);
			this->panel1->Location = System::Drawing::Point(164, 66);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1066, 303);
			this->panel1->TabIndex = 0;
			// 
			// panel3
			// 
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3->Location = System::Drawing::Point(69, 130);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(333, 4);
			this->panel3->TabIndex = 11;
			this->panel3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &deleteUser_UI::panel3_Paint);
			// 
			// username_textBox
			// 
			this->username_textBox->BackColor = System::Drawing::Color::Black;
			this->username_textBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->username_textBox->ForeColor = System::Drawing::Color::White;
			this->username_textBox->Location = System::Drawing::Point(69, 96);
			this->username_textBox->Name = L"username_textBox";
			this->username_textBox->Size = System::Drawing::Size(333, 29);
			this->username_textBox->TabIndex = 10;
			// 
			// username_Label
			// 
			this->username_Label->AutoSize = true;
			this->username_Label->BackColor = System::Drawing::SystemColors::Desktop;
			this->username_Label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16));
			this->username_Label->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->username_Label->Location = System::Drawing::Point(64, 63);
			this->username_Label->Name = L"username_Label";
			this->username_Label->Size = System::Drawing::Size(111, 30);
			this->username_Label->TabIndex = 9;
			this->username_Label->Text = L"Username";
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2->Location = System::Drawing::Point(69, 231);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(333, 4);
			this->panel2->TabIndex = 8;
			// 
			// userID_textBox
			// 
			this->userID_textBox->BackColor = System::Drawing::Color::Black;
			this->userID_textBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->userID_textBox->ForeColor = System::Drawing::Color::White;
			this->userID_textBox->Location = System::Drawing::Point(69, 197);
			this->userID_textBox->Name = L"userID_textBox";
			this->userID_textBox->Size = System::Drawing::Size(333, 29);
			this->userID_textBox->TabIndex = 7;
			// 
			// userID_Label
			// 
			this->userID_Label->AutoSize = true;
			this->userID_Label->BackColor = System::Drawing::SystemColors::Desktop;
			this->userID_Label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16));
			this->userID_Label->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->userID_Label->Location = System::Drawing::Point(64, 164);
			this->userID_Label->Name = L"userID_Label";
			this->userID_Label->Size = System::Drawing::Size(142, 30);
			this->userID_Label->TabIndex = 6;
			this->userID_Label->Text = L"CCCD/CMND";
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Location = System::Drawing::Point(1497, 199);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(8, 8);
			this->flowLayoutPanel1->TabIndex = 1;
			// 
			// exit_Button
			// 
			this->exit_Button->BackColor = System::Drawing::Color::Black;
			this->exit_Button->ForeColor = System::Drawing::Color::White;
			this->exit_Button->Location = System::Drawing::Point(164, 416);
			this->exit_Button->Name = L"exit_Button";
			this->exit_Button->Size = System::Drawing::Size(100, 45);
			this->exit_Button->TabIndex = 7;
			this->exit_Button->Text = L"Exit";
			this->exit_Button->UseVisualStyleBackColor = false;
			this->exit_Button->Click += gcnew System::EventHandler(this, &deleteUser_UI::exit_Button_Click);
			// 
			// delete_User_Button
			// 
			this->delete_User_Button->BackColor = System::Drawing::Color::White;
			this->delete_User_Button->FlatAppearance->BorderSize = 0;
			this->delete_User_Button->ForeColor = System::Drawing::Color::Black;
			this->delete_User_Button->Location = System::Drawing::Point(1130, 416);
			this->delete_User_Button->Name = L"delete_User_Button";
			this->delete_User_Button->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->delete_User_Button->Size = System::Drawing::Size(100, 45);
			this->delete_User_Button->TabIndex = 11;
			this->delete_User_Button->TabStop = false;
			this->delete_User_Button->Text = L"Delete";
			this->delete_User_Button->UseVisualStyleBackColor = false;
			this->delete_User_Button->Click += gcnew System::EventHandler(this, &deleteUser_UI::deleteUser_Button_Click);
			// 
			// resetRFID_Button
			// 
			this->resetRFID_Button->BackColor = System::Drawing::Color::White;
			this->resetRFID_Button->FlatAppearance->BorderSize = 0;
			this->resetRFID_Button->ForeColor = System::Drawing::Color::Black;
			this->resetRFID_Button->Location = System::Drawing::Point(935, 416);
			this->resetRFID_Button->Name = L"resetRFID_Button";
			this->resetRFID_Button->Size = System::Drawing::Size(133, 45);
			this->resetRFID_Button->TabIndex = 12;
			this->resetRFID_Button->TabStop = false;
			this->resetRFID_Button->Text = L"Reset RFID";
			this->resetRFID_Button->UseVisualStyleBackColor = false;
			this->resetRFID_Button->Click += gcnew System::EventHandler(this, &deleteUser_UI::resetRFID_Button_Click);
			// 
			// test_Label
			// 
			this->test_Label->AutoSize = true;
			this->test_Label->ForeColor = System::Drawing::Color::White;
			this->test_Label->Location = System::Drawing::Point(663, 478);
			this->test_Label->Name = L"test_Label";
			this->test_Label->Size = System::Drawing::Size(0, 30);
			this->test_Label->TabIndex = 13;
			// 
			// deleteUser_Button
			// 
			this->deleteUser_Button->AutoSize = true;
			this->deleteUser_Button->ForeColor = System::Drawing::Color::White;
			this->deleteUser_Button->Location = System::Drawing::Point(1107, 478);
			this->deleteUser_Button->Name = L"deleteUser_Button";
			this->deleteUser_Button->Size = System::Drawing::Size(0, 30);
			this->deleteUser_Button->TabIndex = 14;
			// 
			// deleteUser_Label
			// 
			this->deleteUser_Label->AutoSize = true;
			this->deleteUser_Label->ForeColor = System::Drawing::Color::White;
			this->deleteUser_Label->Location = System::Drawing::Point(1074, 495);
			this->deleteUser_Label->Name = L"deleteUser_Label";
			this->deleteUser_Label->Size = System::Drawing::Size(0, 30);
			this->deleteUser_Label->TabIndex = 15;
			// 
			// deleteUser_UI
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1385, 578);
			this->Controls->Add(this->deleteUser_Label);
			this->Controls->Add(this->deleteUser_Button);
			this->Controls->Add(this->test_Label);
			this->Controls->Add(this->resetRFID_Button);
			this->Controls->Add(this->delete_User_Button);
			this->Controls->Add(this->exit_Button);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(6, 7, 6, 7);
			this->Name = L"deleteUser_UI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"deleteUser_UI";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


#pragma region sendDataToESP32UART

private: System::Void sendDataToESP32UART(System::String^ data, size_t length)
{
	// Convert the managed string to a C-style string
	const char* dataStr = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(data)).ToPointer();

	// Open the serial port
	HANDLE hSerial = CreateFile(L"COM4", GENERIC_WRITE | GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hSerial != INVALID_HANDLE_VALUE)
	{
		// Set the serial port parameters
		DCB dcbSerialParams = { 0 };
		dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

		if (GetCommState(hSerial, &dcbSerialParams))
		{
			dcbSerialParams.BaudRate = CBR_115200;  // Set the baud rate
			dcbSerialParams.ByteSize = 8;           // Set the data bits
			dcbSerialParams.Parity = NOPARITY;      // Set no parity
			dcbSerialParams.StopBits = ONESTOPBIT;  // Set one stop bit

			if (SetCommState(hSerial, &dcbSerialParams))
			{
				// Write the data to the serial port
				DWORD bytesWritten;
				if (WriteFile(hSerial, dataStr, strlen(dataStr), &bytesWritten, NULL))
				{
					// Set the timeout value for reading from the serial port
					COMMTIMEOUTS timeouts;
					timeouts.ReadIntervalTimeout = MAXDWORD;
					timeouts.ReadTotalTimeoutMultiplier = 0;
					timeouts.ReadTotalTimeoutConstant = 5000;  // Set the timeout value in milliseconds
					timeouts.WriteTotalTimeoutMultiplier = 0;
					timeouts.WriteTotalTimeoutConstant = 0;
					SetCommTimeouts(hSerial, &timeouts);

					// Read the response from the serial port
					const int bufferSize = 10;  // Adjust the buffer size as needed
					char buffer[bufferSize];
					DWORD bytesRead;

					if (ReadFile(hSerial, buffer, bufferSize - 1, &bytesRead, NULL))
					{
						buffer[bytesRead] = '\0';  // Null-terminate the received data

						// Check the received number code
						int code = atoi(buffer);

						switch (code)
						{
						case 1:
							// Successful write
							test_Label->ForeColor = System::Drawing::Color::Green;
							test_Label->Text = "Write Succesfully";
							break;
						case 2:
							// Failed to write
							test_Label->ForeColor = System::Drawing::Color::Red;
							test_Label->Text = "Failed to Write";
							break;
						default:
							// Failed to write
							test_Label->ForeColor = System::Drawing::Color::Red;
							test_Label->Text = "No Response1";
							break;
						}
					}
					else
					{
						// Failed to read response within the timeout period
						test_Label->ForeColor = System::Drawing::Color::Red;
						test_Label->Text = "No Response2";
					}
				}
			}
		}
		// Close the serial port
		CloseHandle(hSerial);
	}

	// Free the allocated memory
	System::Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr((void*)dataStr));
}


#pragma endregion
#pragma region convert_SysStr_To_StdStr

	private: std::string convert_SysStr_To_StdStr(System::String^ Sys_str)
	{
		// Convert the System::String to std::string
		std::string std_str = msclr::interop::marshal_as<std::string>(Sys_str);
		return std_str;
	}

#pragma endregion
#pragma region convert_StdStr_To_SysStr

	private: System::String^ convert_StdStr_To_SysStr(std::string Std_str)
	{
		// Convert the std::string to System::String
		System::String^ Sys_str = gcnew System::String(Std_str.c_str());
		return Sys_str;
	}

#pragma endregion
#pragma region deleteUserFB
	private: void deleteUserOnFB(System::String^ Username, System::String^ USER_ID) {
		std::string username = convert_SysStr_To_StdStr(Username);
		std::string user_id = convert_SysStr_To_StdStr(USER_ID);

		std::string command = "python3 deleteUserFB.py " + user_id;
		int result = system(command.c_str());
		if (result == -1) {
			// Error occurred while executing the command
			deleteUser_Label->ForeColor = System::Drawing::Color::Red;
			deleteUser_Label->Text = "Failed to delete";
		}
		else {
			// Command executed successfully

			deleteUser_Label->ForeColor = System::Drawing::Color::Green;
			deleteUser_Label->Text = "Successfully delete";
		}
	}


#pragma endregion


	private: System::Void exit_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
	}
	private: System::Void deleteUser_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		deleteUserOnFB(username_textBox->Text, userID_textBox->Text);
	}
private: System::Void panel3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void resetRFID_Button_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string resetData = "000000000000";
	size_t length = resetData.length();

	// Send the data to ESP32
	sendDataToESP32UART(convert_StdStr_To_SysStr(resetData), length);
}

};
}
