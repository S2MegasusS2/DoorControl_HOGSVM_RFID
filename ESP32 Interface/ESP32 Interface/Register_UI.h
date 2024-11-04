#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <Windows.h>

#include <rapidjson/filereadstream.h>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include "rapidjson/rapidjson.h"
#include <msclr/marshal_cppstd.h>

#include <opencv/build/include/opencv2/opencv.hpp>
#include <opencv/build/include/opencv2/video.hpp>

#pragma region LocalVariables
	cv::VideoCapture capture;
	cv::Mat frame;
#pragma endregion


using namespace System;
 
namespace ESP32Interface {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Threading;
	using namespace System::Threading::Tasks;
	using namespace System::Runtime::InteropServices;
	using namespace cv;

	/// <summary>
	/// Summary for Register_UI
	/// </summary>
	public ref class Register_UI : public System::Windows::Forms::Form
	{
	public:
		Register_UI(void)
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
		~Register_UI()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::TextBox^ username_textBox;
	private: System::Windows::Forms::Label^ username_Label;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ ID_textBox;



	private: System::Windows::Forms::Label^ ID_Label;

	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::TextBox^ time_reg_textBox;

	private: System::Windows::Forms::Label^ time_register_Label;

	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::TextBox^ roomID_textBox;

	private: System::Windows::Forms::Label^ roomID_Label;

	private: System::Windows::Forms::Panel^ bounding_Panel;

	private: System::Windows::Forms::Button^ exit_Button;
	private: System::Windows::Forms::Button^ reg_Button;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ reg_status_Label;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::TextBox^ time_start_reg_textBox;

	private: System::Windows::Forms::Label^ time_start_reg_Label;
	private: System::Windows::Forms::Button^ get_Img_Button;
	private: System::Windows::Forms::Panel^ get_img_Panel;

	private: System::Windows::Forms::Button^ get_screenshot_Button;

	private: System::Windows::Forms::TextBox^ webcam_boundary_panel;

	private: System::Windows::Forms::Label^ webcam_Label;
	private: System::Windows::Forms::Button^ exit_get_img_Button;
	private: System::Windows::Forms::PictureBox^ camera_PictureBox;
	private: System::Windows::Forms::Label^ getImg_status_Label;
	private: System::Windows::Forms::Button^ write_RFID_Button;
	private: System::Windows::Forms::Label^ test_Label;






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

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->username_textBox = (gcnew System::Windows::Forms::TextBox());
			this->username_Label = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->ID_textBox = (gcnew System::Windows::Forms::TextBox());
			this->ID_Label = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->time_reg_textBox = (gcnew System::Windows::Forms::TextBox());
			this->time_register_Label = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->roomID_textBox = (gcnew System::Windows::Forms::TextBox());
			this->roomID_Label = (gcnew System::Windows::Forms::Label());
			this->bounding_Panel = (gcnew System::Windows::Forms::Panel());
			this->get_img_Panel = (gcnew System::Windows::Forms::Panel());
			this->getImg_status_Label = (gcnew System::Windows::Forms::Label());
			this->camera_PictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->exit_get_img_Button = (gcnew System::Windows::Forms::Button());
			this->get_screenshot_Button = (gcnew System::Windows::Forms::Button());
			this->webcam_boundary_panel = (gcnew System::Windows::Forms::TextBox());
			this->webcam_Label = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->time_start_reg_textBox = (gcnew System::Windows::Forms::TextBox());
			this->time_start_reg_Label = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->exit_Button = (gcnew System::Windows::Forms::Button());
			this->reg_Button = (gcnew System::Windows::Forms::Button());
			this->reg_status_Label = (gcnew System::Windows::Forms::Label());
			this->get_Img_Button = (gcnew System::Windows::Forms::Button());
			this->write_RFID_Button = (gcnew System::Windows::Forms::Button());
			this->test_Label = (gcnew System::Windows::Forms::Label());
			this->bounding_Panel->SuspendLayout();
			this->get_img_Panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->camera_PictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// username_textBox
			// 
			this->username_textBox->BackColor = System::Drawing::Color::Black;
			this->username_textBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->username_textBox->ForeColor = System::Drawing::Color::White;
			this->username_textBox->Location = System::Drawing::Point(112, 109);
			this->username_textBox->Name = L"username_textBox";
			this->username_textBox->Size = System::Drawing::Size(333, 29);
			this->username_textBox->TabIndex = 1;
			// 
			// username_Label
			// 
			this->username_Label->AutoSize = true;
			this->username_Label->BackColor = System::Drawing::SystemColors::Desktop;
			this->username_Label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16));
			this->username_Label->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->username_Label->Location = System::Drawing::Point(107, 76);
			this->username_Label->Name = L"username_Label";
			this->username_Label->Size = System::Drawing::Size(107, 30);
			this->username_Label->TabIndex = 6;
			this->username_Label->Text = L"Họ và tên";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel2->Location = System::Drawing::Point(112, 226);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(333, 4);
			this->panel2->TabIndex = 11;
			// 
			// ID_textBox
			// 
			this->ID_textBox->BackColor = System::Drawing::Color::Black;
			this->ID_textBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ID_textBox->ForeColor = System::Drawing::Color::White;
			this->ID_textBox->Location = System::Drawing::Point(112, 192);
			this->ID_textBox->Name = L"ID_textBox";
			this->ID_textBox->Size = System::Drawing::Size(333, 29);
			this->ID_textBox->TabIndex = 2;
			// 
			// ID_Label
			// 
			this->ID_Label->AutoSize = true;
			this->ID_Label->BackColor = System::Drawing::SystemColors::Desktop;
			this->ID_Label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16));
			this->ID_Label->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->ID_Label->Location = System::Drawing::Point(107, 159);
			this->ID_Label->Name = L"ID_Label";
			this->ID_Label->Size = System::Drawing::Size(142, 30);
			this->ID_Label->TabIndex = 9;
			this->ID_Label->Text = L"CCCD/CMND";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel3->Location = System::Drawing::Point(112, 311);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(333, 4);
			this->panel3->TabIndex = 14;
			// 
			// time_reg_textBox
			// 
			this->time_reg_textBox->BackColor = System::Drawing::Color::Black;
			this->time_reg_textBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->time_reg_textBox->ForeColor = System::Drawing::Color::White;
			this->time_reg_textBox->Location = System::Drawing::Point(112, 277);
			this->time_reg_textBox->Name = L"time_reg_textBox";
			this->time_reg_textBox->Size = System::Drawing::Size(333, 29);
			this->time_reg_textBox->TabIndex = 3;
			// 
			// time_register_Label
			// 
			this->time_register_Label->AutoSize = true;
			this->time_register_Label->BackColor = System::Drawing::SystemColors::Desktop;
			this->time_register_Label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16));
			this->time_register_Label->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->time_register_Label->Location = System::Drawing::Point(107, 244);
			this->time_register_Label->Name = L"time_register_Label";
			this->time_register_Label->Size = System::Drawing::Size(202, 30);
			this->time_register_Label->TabIndex = 12;
			this->time_register_Label->Text = L"Thời hạn đặt phòng";
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel4->Location = System::Drawing::Point(112, 480);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(333, 4);
			this->panel4->TabIndex = 17;
			// 
			// roomID_textBox
			// 
			this->roomID_textBox->BackColor = System::Drawing::Color::Black;
			this->roomID_textBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->roomID_textBox->ForeColor = System::Drawing::Color::White;
			this->roomID_textBox->Location = System::Drawing::Point(112, 446);
			this->roomID_textBox->Name = L"roomID_textBox";
			this->roomID_textBox->Size = System::Drawing::Size(333, 29);
			this->roomID_textBox->TabIndex = 5;
			// 
			// roomID_Label
			// 
			this->roomID_Label->AutoSize = true;
			this->roomID_Label->BackColor = System::Drawing::SystemColors::Desktop;
			this->roomID_Label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16));
			this->roomID_Label->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->roomID_Label->Location = System::Drawing::Point(107, 413);
			this->roomID_Label->Name = L"roomID_Label";
			this->roomID_Label->Size = System::Drawing::Size(107, 30);
			this->roomID_Label->TabIndex = 15;
			this->roomID_Label->Text = L"Số phòng";
			// 
			// bounding_Panel
			// 
			this->bounding_Panel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->bounding_Panel->Controls->Add(this->get_img_Panel);
			this->bounding_Panel->Controls->Add(this->panel5);
			this->bounding_Panel->Controls->Add(this->time_start_reg_textBox);
			this->bounding_Panel->Controls->Add(this->time_start_reg_Label);
			this->bounding_Panel->Controls->Add(this->panel4);
			this->bounding_Panel->Controls->Add(this->roomID_textBox);
			this->bounding_Panel->Controls->Add(this->roomID_Label);
			this->bounding_Panel->Controls->Add(this->panel3);
			this->bounding_Panel->Controls->Add(this->time_reg_textBox);
			this->bounding_Panel->Controls->Add(this->time_register_Label);
			this->bounding_Panel->Controls->Add(this->panel2);
			this->bounding_Panel->Controls->Add(this->ID_textBox);
			this->bounding_Panel->Controls->Add(this->ID_Label);
			this->bounding_Panel->Controls->Add(this->panel1);
			this->bounding_Panel->Controls->Add(this->username_textBox);
			this->bounding_Panel->Controls->Add(this->username_Label);
			this->bounding_Panel->Location = System::Drawing::Point(238, 78);
			this->bounding_Panel->Name = L"bounding_Panel";
			this->bounding_Panel->Size = System::Drawing::Size(1118, 699);
			this->bounding_Panel->TabIndex = 18;
			// 
			// get_img_Panel
			// 
			this->get_img_Panel->BackColor = System::Drawing::Color::Black;
			this->get_img_Panel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->get_img_Panel->Controls->Add(this->getImg_status_Label);
			this->get_img_Panel->Controls->Add(this->camera_PictureBox);
			this->get_img_Panel->Controls->Add(this->exit_get_img_Button);
			this->get_img_Panel->Controls->Add(this->get_screenshot_Button);
			this->get_img_Panel->Controls->Add(this->webcam_boundary_panel);
			this->get_img_Panel->Controls->Add(this->webcam_Label);
			this->get_img_Panel->Location = System::Drawing::Point(46, 26);
			this->get_img_Panel->Name = L"get_img_Panel";
			this->get_img_Panel->Size = System::Drawing::Size(1022, 635);
			this->get_img_Panel->TabIndex = 21;
			this->get_img_Panel->Visible = false;
			// 
			// getImg_status_Label
			// 
			this->getImg_status_Label->AutoSize = true;
			this->getImg_status_Label->ForeColor = System::Drawing::Color::White;
			this->getImg_status_Label->Location = System::Drawing::Point(513, 584);
			this->getImg_status_Label->Name = L"getImg_status_Label";
			this->getImg_status_Label->Size = System::Drawing::Size(0, 30);
			this->getImg_status_Label->TabIndex = 13;
			// 
			// camera_PictureBox
			// 
			this->camera_PictureBox->Location = System::Drawing::Point(253, 115);
			this->camera_PictureBox->Name = L"camera_PictureBox";
			this->camera_PictureBox->Size = System::Drawing::Size(521, 403);
			this->camera_PictureBox->TabIndex = 12;
			this->camera_PictureBox->TabStop = false;
			// 
			// exit_get_img_Button
			// 
			this->exit_get_img_Button->BackColor = System::Drawing::Color::Black;
			this->exit_get_img_Button->ForeColor = System::Drawing::Color::White;
			this->exit_get_img_Button->Location = System::Drawing::Point(101, 537);
			this->exit_get_img_Button->Name = L"exit_get_img_Button";
			this->exit_get_img_Button->Size = System::Drawing::Size(100, 45);
			this->exit_get_img_Button->TabIndex = 11;
			this->exit_get_img_Button->Text = L"Exit";
			this->exit_get_img_Button->UseVisualStyleBackColor = false;
			this->exit_get_img_Button->Click += gcnew System::EventHandler(this, &Register_UI::exit_get_img_Click);
			// 
			// get_screenshot_Button
			// 
			this->get_screenshot_Button->BackColor = System::Drawing::Color::White;
			this->get_screenshot_Button->FlatAppearance->BorderSize = 0;
			this->get_screenshot_Button->ForeColor = System::Drawing::Color::Black;
			this->get_screenshot_Button->Location = System::Drawing::Point(800, 537);
			this->get_screenshot_Button->Name = L"get_screenshot_Button";
			this->get_screenshot_Button->Size = System::Drawing::Size(106, 37);
			this->get_screenshot_Button->TabIndex = 10;
			this->get_screenshot_Button->TabStop = false;
			this->get_screenshot_Button->Text = L"Get";
			this->get_screenshot_Button->UseVisualStyleBackColor = false;
			this->get_screenshot_Button->Click += gcnew System::EventHandler(this, &Register_UI::get_screenshot_Button_Click);
			// 
			// webcam_boundary_panel
			// 
			this->webcam_boundary_panel->BackColor = System::Drawing::Color::Black;
			this->webcam_boundary_panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->webcam_boundary_panel->ForeColor = System::Drawing::Color::White;
			this->webcam_boundary_panel->Location = System::Drawing::Point(66, 88);
			this->webcam_boundary_panel->Multiline = true;
			this->webcam_boundary_panel->Name = L"webcam_boundary_panel";
			this->webcam_boundary_panel->ReadOnly = true;
			this->webcam_boundary_panel->Size = System::Drawing::Size(878, 443);
			this->webcam_boundary_panel->TabIndex = 2;
			this->webcam_boundary_panel->TabStop = false;
			// 
			// webcam_Label
			// 
			this->webcam_Label->AutoSize = true;
			this->webcam_Label->BackColor = System::Drawing::SystemColors::Desktop;
			this->webcam_Label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24));
			this->webcam_Label->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->webcam_Label->Location = System::Drawing::Point(62, 40);
			this->webcam_Label->Name = L"webcam_Label";
			this->webcam_Label->Size = System::Drawing::Size(451, 45);
			this->webcam_Label->TabIndex = 1;
			this->webcam_Label->Text = L"Get User Image from Webcam";
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel5->Location = System::Drawing::Point(112, 396);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(333, 4);
			this->panel5->TabIndex = 20;
			// 
			// time_start_reg_textBox
			// 
			this->time_start_reg_textBox->BackColor = System::Drawing::Color::Black;
			this->time_start_reg_textBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->time_start_reg_textBox->ForeColor = System::Drawing::Color::White;
			this->time_start_reg_textBox->Location = System::Drawing::Point(112, 362);
			this->time_start_reg_textBox->Name = L"time_start_reg_textBox";
			this->time_start_reg_textBox->Size = System::Drawing::Size(333, 29);
			this->time_start_reg_textBox->TabIndex = 4;
			// 
			// time_start_reg_Label
			// 
			this->time_start_reg_Label->AutoSize = true;
			this->time_start_reg_Label->BackColor = System::Drawing::SystemColors::Desktop;
			this->time_start_reg_Label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16));
			this->time_start_reg_Label->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->time_start_reg_Label->Location = System::Drawing::Point(107, 329);
			this->time_start_reg_Label->Name = L"time_start_reg_Label";
			this->time_start_reg_Label->Size = System::Drawing::Size(101, 30);
			this->time_start_reg_Label->TabIndex = 19;
			this->time_start_reg_Label->Text = L"Ngày đặt";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel1->Location = System::Drawing::Point(112, 143);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(333, 4);
			this->panel1->TabIndex = 8;
			// 
			// exit_Button
			// 
			this->exit_Button->BackColor = System::Drawing::Color::Black;
			this->exit_Button->ForeColor = System::Drawing::Color::White;
			this->exit_Button->Location = System::Drawing::Point(262, 801);
			this->exit_Button->Name = L"exit_Button";
			this->exit_Button->Size = System::Drawing::Size(100, 45);
			this->exit_Button->TabIndex = 6;
			this->exit_Button->Text = L"Exit";
			this->exit_Button->UseVisualStyleBackColor = false;
			this->exit_Button->Click += gcnew System::EventHandler(this, &Register_UI::exit_Button_Click);
			// 
			// reg_Button
			// 
			this->reg_Button->BackColor = System::Drawing::Color::White;
			this->reg_Button->ForeColor = System::Drawing::Color::Black;
			this->reg_Button->Location = System::Drawing::Point(1216, 801);
			this->reg_Button->Name = L"reg_Button";
			this->reg_Button->Size = System::Drawing::Size(100, 45);
			this->reg_Button->TabIndex = 5;
			this->reg_Button->Text = L"Register";
			this->reg_Button->UseVisualStyleBackColor = false;
			this->reg_Button->Click += gcnew System::EventHandler(this, &Register_UI::reg_Button_Click);
			// 
			// reg_status_Label
			// 
			this->reg_status_Label->AutoSize = true;
			this->reg_status_Label->ForeColor = System::Drawing::Color::Red;
			this->reg_status_Label->Location = System::Drawing::Point(1083, 866);
			this->reg_status_Label->Name = L"reg_status_Label";
			this->reg_status_Label->Size = System::Drawing::Size(0, 30);
			this->reg_status_Label->TabIndex = 21;
			// 
			// get_Img_Button
			// 
			this->get_Img_Button->BackColor = System::Drawing::Color::White;
			this->get_Img_Button->ForeColor = System::Drawing::Color::Black;
			this->get_Img_Button->Location = System::Drawing::Point(1088, 801);
			this->get_Img_Button->Name = L"get_Img_Button";
			this->get_Img_Button->Size = System::Drawing::Size(100, 45);
			this->get_Img_Button->TabIndex = 22;
			this->get_Img_Button->Text = L"Get Img";
			this->get_Img_Button->UseVisualStyleBackColor = false;
			this->get_Img_Button->Click += gcnew System::EventHandler(this, &Register_UI::get_Img_Button_Click);
			// 
			// write_RFID_Button
			// 
			this->write_RFID_Button->BackColor = System::Drawing::Color::White;
			this->write_RFID_Button->ForeColor = System::Drawing::Color::Black;
			this->write_RFID_Button->Location = System::Drawing::Point(926, 801);
			this->write_RFID_Button->Name = L"write_RFID_Button";
			this->write_RFID_Button->Size = System::Drawing::Size(136, 45);
			this->write_RFID_Button->TabIndex = 23;
			this->write_RFID_Button->Text = L"Write RFID";
			this->write_RFID_Button->UseVisualStyleBackColor = false;
			this->write_RFID_Button->Click += gcnew System::EventHandler(this, &Register_UI::write_RFID_Button_Click);
			// 
			// test_Label
			// 
			this->test_Label->AutoSize = true;
			this->test_Label->ForeColor = System::Drawing::Color::White;
			this->test_Label->Location = System::Drawing::Point(577, 876);
			this->test_Label->Name = L"test_Label";
			this->test_Label->Size = System::Drawing::Size(0, 30);
			this->test_Label->TabIndex = 24;
			// 
			// Register_UI
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(1600, 1024);
			this->Controls->Add(this->test_Label);
			this->Controls->Add(this->write_RFID_Button);
			this->Controls->Add(this->get_Img_Button);
			this->Controls->Add(this->reg_status_Label);
			this->Controls->Add(this->reg_Button);
			this->Controls->Add(this->exit_Button);
			this->Controls->Add(this->bounding_Panel);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(6, 7, 6, 7);
			this->Name = L"Register_UI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Register_UI";
			this->Load += gcnew System::EventHandler(this, &Register_UI::Register_UI_Load);
			this->bounding_Panel->ResumeLayout(false);
			this->bounding_Panel->PerformLayout();
			this->get_img_Panel->ResumeLayout(false);
			this->get_img_Panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->camera_PictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma region LocalVariables
	private: Thread^ StreamThreadHandle;
	private: int camera_device = 0;
	private: Bitmap^ bitmap;
	private: System::String^ screenshotPath = "./Data/Img/";
	private: uint16_t screenshotWidth = 600;
	private: uint16_t screenshotHeight = 480;
    private: int screenshotCount = 1;
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

#pragma region Delegates

	private: delegate void UPDATE_FRAME(Bitmap^ bit);

	private: void UpdateFrame(Bitmap^ bit)
	{
		camera_PictureBox->Image = bit;
	}
	UPDATE_FRAME^ cb;
#pragma endregion

#pragma region ThreadsFunction
	private: System::Void StreamThread()
	{
		capture.open(camera_device);
		if (!capture.isOpened()) {
			MessageBox::Show("Error: No camera is found!");
			return;
		}

		// Reading frame
		while (capture.read(frame)) {
			if (frame.empty()) {
				break;
			}

			// Update to the camera_PictureBox
			if (camera_PictureBox->InvokeRequired) {
				// This is a thread which is not same thread creating the camera_PictureBox.
				// Need to use delegate to update
				cb = gcnew UPDATE_FRAME(this, &Register_UI::UpdateFrame);

				// Convert opencv Mat to bitmap
				bitmap = gcnew Bitmap(frame.cols, frame.rows, frame.step, Imaging::PixelFormat::Format24bppRgb, System::IntPtr(frame.data));

				// Invoke the delegate update func
				Control::Invoke(cb, bitmap);
			}
			else {
				// In case camera_PictureBox is created at same thread, invoke is not required
				UpdateFrame(bitmap);
			}
		}
	}
#pragma endregion

#pragma region ButtonDisAndEnFunc
	// Enable and disable register button form
	void disableRegisterFormButton() {
		exit_Button->Enabled = FALSE;
		reg_Button->Enabled = FALSE;
		get_Img_Button->Enabled = FALSE;
	}
	void enableRergisterFormButton() {
		exit_Button->Enabled = TRUE;
		reg_Button->Enabled = TRUE;
		get_Img_Button->Enabled = TRUE;
	}

	// Check empty textbox
	bool checkEmptyTextBox() {
		if (System::String::IsNullOrEmpty(username_textBox->Text)) return false;
		if (System::String::IsNullOrEmpty(ID_textBox->Text)) return false;
		if (System::String::IsNullOrEmpty(time_reg_textBox->Text)) return false;
		if (System::String::IsNullOrEmpty(roomID_textBox->Text)) return false;
		if (System::String::IsNullOrEmpty(time_start_reg_textBox->Text)) return false;
		return true;
	}

	private: System::Void Register_UI_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: void clearAllDataTextBox() {
		username_textBox->Text = "";
		ID_textBox->Text = "";
		time_reg_textBox->Text = "";
		roomID_textBox->Text = "";
	}
	private: System::Void exit_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		clearAllDataTextBox();
		this->Hide();
	}
#pragma endregion

#pragma region convertRoomIDtoESP32_ID
	
	private: std::string convertRoomIDtoESP32_ID(std::string roomID)
	{
		// Open Databank.json file
		std::ifstream file("Databank.json");
		if (!file.is_open()) {
			std::cerr << "Error opening Databank.json file." << std::endl;
			return "";
		}

		// Read file content into a string
		std::string fileContent;
		std::getline(file, fileContent, '\0');

		// Parse JSON data
		rapidjson::Document document;
		document.Parse(fileContent.c_str());
		if (document.HasParseError()) {
			std::cerr << "Error parsing JSON data: " << document.GetParseError() << std::endl;
			return "";
		}

		// Find matching ESP32_ID
		std::string esp32ID;
		for (const auto& esp32Obj : document["ESP32_ID"].GetArray()) {
			for (const auto& id : esp32Obj.GetObject()) {
				if (id.name.GetString() == roomID) {
					esp32ID = id.value.GetString();
					break;
				}
			}
			if (!esp32ID.empty()) {
				break;
			}
		}

		// Close file
		file.close();

		// Return ESP32_ID
		return esp32ID;
	}

#pragma endregion

#pragma region SaveUserToJsonFile
	private: void SaveDataToJsonFile()
	{
		// Get the values from text boxes
		System::String^ username = username_textBox->Text;
		System::String^ id = ID_textBox->Text;
		System::String^ registrationTime = time_reg_textBox->Text;
		System::String^ roomId = roomID_textBox->Text;
		System::String^ regStartTime = time_start_reg_textBox->Text;

		// Convert the strings to standard C++ strings
		std::string usernameStr = msclr::interop::marshal_as<std::string>(username);
		std::string idStr = msclr::interop::marshal_as<std::string>(id);
		std::string registrationTimeStr = msclr::interop::marshal_as<std::string>(registrationTime);
		std::string roomIdStr = msclr::interop::marshal_as<std::string>(roomId);
		std::string regStartTimeStr = msclr::interop::marshal_as<std::string>(regStartTime);

		// Convert RoomID to ESP32_ID
		roomIdStr = convertRoomIDtoESP32_ID(roomIdStr);

		// Create a RapidJSON document
		rapidjson::Document document;
		document.SetObject();

		// Add data to the document
		rapidjson::Document::AllocatorType& allocator = document.GetAllocator();

		document.AddMember("username", rapidjson::Value(usernameStr.c_str(), allocator).Move(), allocator);
		document.AddMember("id", rapidjson::Value(idStr.c_str(), allocator).Move(), allocator);
		document.AddMember("registrationTime", rapidjson::Value(registrationTimeStr.c_str(), allocator).Move(), allocator);
		document.AddMember("roomId", rapidjson::Value(roomIdStr.c_str(), allocator).Move(), allocator);
		document.AddMember("regStartTime", rapidjson::Value(regStartTimeStr.c_str(), allocator).Move(), allocator);

		// Convert the document to a JSON string
		rapidjson::StringBuffer buffer;
		rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
		document.Accept(writer);

		// Save the JSON string to a file
		std::string fileName = msclr::interop::marshal_as<std::string>(username) + ".json";  // Construct the filename
		std::string filePath = "./Data/Info/" + fileName;  // Specify the file path including the filename
		std::ofstream outputFile(filePath);
		if (outputFile.is_open())
		{
			outputFile << buffer.GetString();
			outputFile.close();
			reg_status_Label->ForeColor = System::Drawing::Color::Green;
			reg_status_Label->Text = System::String::Concat("Data saved to ", gcnew System::String(fileName.c_str()));
		}
		else
		{
			reg_status_Label->ForeColor = System::Drawing::Color::Red;
			reg_status_Label->Text = "Failed to open " + gcnew System::String(fileName.c_str()) + " for writing";
		}
	}
#pragma endregion

#pragma region UploadDB
	private: void sendDataToFirestoreDB() {
		system("python3 uploadFirestoreDB.py");
	}

	private: void sendImgToFirestoreStorage() {
		system("python3 sendImgToDB.py");
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
					timeouts.ReadTotalTimeoutConstant = 3000;  // Set the timeout value in milliseconds
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

#pragma region sendRoomIDtoESP32RFID
private: System::Void sendRoomIDtoESP32RFID() {
	// Get values from text boxes
	System::String^ roomId = roomID_textBox->Text;

	// Convert System::String^ to std::string
	std::string roomIDStr = msclr::interop::marshal_as<std::string>(roomId);

	// Convert roomId to MAC_ESP32 using convertRoomIDtoESP32_ID
	std::string MAC_ESP32 = convertRoomIDtoESP32_ID(roomIDStr);

	// Get the length of MAC_ESP32
	size_t length = MAC_ESP32.length();

	// Send the data to ESP32
	sendDataToESP32UART(convert_StdStr_To_SysStr(MAC_ESP32), length);
}
#pragma endregion

private: System::Void reg_Button_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!checkEmptyTextBox())
	{
		reg_status_Label->ForeColor = System::Drawing::Color::Red;
		reg_status_Label->Text = "Fill all empty textbox!";
	}
	else {
		SaveDataToJsonFile();
		sendDataToFirestoreDB();
		sendImgToFirestoreStorage();
	}
}
private: System::Void get_Img_Button_Click(System::Object^ sender, System::EventArgs^ e) {
	get_img_Panel->Visible = TRUE;
	disableRegisterFormButton();
	StreamThreadHandle = gcnew Thread(gcnew ThreadStart(this, &Register_UI::StreamThread));
	StreamThreadHandle->Start();
}
private: System::Void get_screenshot_Button_Click(System::Object^ sender, System::EventArgs^ e) {
	System::String^ folderPath = screenshotPath + username_textBox->Text;
	System::IO::Directory::CreateDirectory(folderPath);

	System::String^ screenshotImgName = username_textBox->Text + "_" + screenshotCount.ToString() + ".jpg";
	System::String^ screenshotPath = System::IO::Path::Combine(folderPath, screenshotImgName);
	screenshotPath = screenshotPath->Replace("\\", "/");

	bitmap->Save(screenshotPath, System::Drawing::Imaging::ImageFormat::Jpeg);
	screenshotCount++;
		
	getImg_status_Label->Text = screenshotPath;
}
private: System::Void exit_get_img_Click(System::Object^ sender, System::EventArgs^ e) {
	get_img_Panel->Visible = FALSE;

	if (StreamThreadHandle != nullptr) {
		if ((StreamThreadHandle->IsAlive) == TRUE) {
			StreamThreadHandle->Abort();
		}
	}

	screenshotCount = 1;
	enableRergisterFormButton();
}
private: System::Void write_RFID_Button_Click(System::Object^ sender, System::EventArgs^ e) {
	test_Label->Text = "";
	sendRoomIDtoESP32RFID();
}
};
}
