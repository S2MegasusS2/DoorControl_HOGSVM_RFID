#pragma once

namespace ESP32Interface {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Room1_UI
	/// </summary>
	public ref class Room1_UI : public System::Windows::Forms::Form
	{
	public:
		Room1_UI(void)
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
		~Room1_UI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ roomID_Label;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutStatus_Panel;

	private: System::Windows::Forms::Label^ registerDate_Label;
	private: System::Windows::Forms::Button^ exit_get_img_Button;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Room1_UI::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutStatus_Panel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->registerDate_Label = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->roomID_Label = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->exit_get_img_Button = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->tableLayoutStatus_Panel);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Location = System::Drawing::Point(63, 53);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1456, 810);
			this->panel1->TabIndex = 0;
			// 
			// tableLayoutStatus_Panel
			// 
			this->tableLayoutStatus_Panel->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Inset;
			this->tableLayoutStatus_Panel->ColumnCount = 3;
			this->tableLayoutStatus_Panel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				30)));
			this->tableLayoutStatus_Panel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutStatus_Panel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutStatus_Panel->ForeColor = System::Drawing::Color::White;
			this->tableLayoutStatus_Panel->Location = System::Drawing::Point(463, 350);
			this->tableLayoutStatus_Panel->Name = L"tableLayoutStatus_Panel";
			this->tableLayoutStatus_Panel->RowCount = 8;
			this->tableLayoutStatus_Panel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				35)));
			this->tableLayoutStatus_Panel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				50)));
			this->tableLayoutStatus_Panel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				50)));
			this->tableLayoutStatus_Panel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				50)));
			this->tableLayoutStatus_Panel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				50)));
			this->tableLayoutStatus_Panel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				50)));
			this->tableLayoutStatus_Panel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				50)));
			this->tableLayoutStatus_Panel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				50)));
			this->tableLayoutStatus_Panel->Size = System::Drawing::Size(909, 413);
			this->tableLayoutStatus_Panel->TabIndex = 1;
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->registerDate_Label);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->roomID_Label);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->pictureBox1);
			this->panel2->Location = System::Drawing::Point(47, 35);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(316, 728);
			this->panel2->TabIndex = 0;
			// 
			// registerDate_Label
			// 
			this->registerDate_Label->AutoSize = true;
			this->registerDate_Label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18));
			this->registerDate_Label->ForeColor = System::Drawing::Color::White;
			this->registerDate_Label->Location = System::Drawing::Point(25, 490);
			this->registerDate_Label->Name = L"registerDate_Label";
			this->registerDate_Label->Size = System::Drawing::Size(0, 32);
			this->registerDate_Label->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(25, 469);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(156, 32);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Register Date";
			// 
			// roomID_Label
			// 
			this->roomID_Label->AutoSize = true;
			this->roomID_Label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18));
			this->roomID_Label->ForeColor = System::Drawing::Color::White;
			this->roomID_Label->Location = System::Drawing::Point(25, 416);
			this->roomID_Label->Name = L"roomID_Label";
			this->roomID_Label->Size = System::Drawing::Size(131, 32);
			this->roomID_Label->TabIndex = 2;
			this->roomID_Label->Text = L"Room ID: 1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(25, 364);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(263, 32);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Pham Nguyen Tan Phat";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(28, 30);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(260, 320);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// exit_get_img_Button
			// 
			this->exit_get_img_Button->BackColor = System::Drawing::Color::Black;
			this->exit_get_img_Button->ForeColor = System::Drawing::Color::White;
			this->exit_get_img_Button->Location = System::Drawing::Point(712, 900);
			this->exit_get_img_Button->Name = L"exit_get_img_Button";
			this->exit_get_img_Button->Size = System::Drawing::Size(100, 45);
			this->exit_get_img_Button->TabIndex = 13;
			this->exit_get_img_Button->Text = L"Exit";
			this->exit_get_img_Button->UseVisualStyleBackColor = false;
			this->exit_get_img_Button->Click += gcnew System::EventHandler(this, &Room1_UI::exit_room1_Button_Click);
			// 
			// Room1_UI
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(1600, 1024);
			this->Controls->Add(this->exit_get_img_Button);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16));
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(6, 7, 6, 7);
			this->Name = L"Room1_UI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Room1_UI";
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

#pragma region createLabelForTableLayout
private: System::Void createLabelForTableLayout() {
	// Add labels for the rows
	for (int row = 0; row < 8; row++) {
		// Create labels in every row
		this->tableLayoutStatus_Panel->Controls->Add(gcnew System::Windows::Forms::Label(), 0, row);
		this->tableLayoutStatus_Panel->Controls->Add(gcnew System::Windows::Forms::Label(), 1, row);
		this->tableLayoutStatus_Panel->Controls->Add(gcnew System::Windows::Forms::Label(), 2, row);

		// Increase the width of the labels to accommodate the full context
		this->tableLayoutStatus_Panel->GetControlFromPosition(0, row)->Width = 250;
		this->tableLayoutStatus_Panel->GetControlFromPosition(1, row)->Width = 500;
		this->tableLayoutStatus_Panel->GetControlFromPosition(2, row)->Width = 200;

		// Set AutoSize property to false to prevent truncation of the text
		this->tableLayoutStatus_Panel->GetControlFromPosition(0, row)->AutoSize = false;
		this->tableLayoutStatus_Panel->GetControlFromPosition(1, row)->AutoSize = false;
		this->tableLayoutStatus_Panel->GetControlFromPosition(2, row)->AutoSize = false;
		// Set text for the labels in the remaining rows
		this->tableLayoutStatus_Panel->GetControlFromPosition(0, row)->Text = "";
		this->tableLayoutStatus_Panel->GetControlFromPosition(1, row)->Text = "";
		this->tableLayoutStatus_Panel->GetControlFromPosition(2, row)->Text = "";
	}

	// Set text for the labels in the first row
	this->tableLayoutStatus_Panel->GetControlFromPosition(0, 0)->Text = "Time";
	this->tableLayoutStatus_Panel->GetControlFromPosition(1, 0)->Text = "Name";
	this->tableLayoutStatus_Panel->GetControlFromPosition(2, 0)->Text = "Method";

	this->tableLayoutStatus_Panel->GetControlFromPosition(0, 1)->Text = "6/24/2024 7:53:42 AM";
	this->tableLayoutStatus_Panel->GetControlFromPosition(1, 1)->Text = "Pham Nguyen Tan Phat";
	this->tableLayoutStatus_Panel->GetControlFromPosition(2, 1)->Text = "Scan face";

	this->tableLayoutStatus_Panel->GetControlFromPosition(0, 2)->Text = "6/25/2024 11:41:27 AM";
	this->tableLayoutStatus_Panel->GetControlFromPosition(1, 2)->Text = "Nguyen Quang Phuoc";
	this->tableLayoutStatus_Panel->GetControlFromPosition(2, 2)->Text = "Scan card";
}
#pragma endregion
#pragma region exit_Room1_UI
private: System::Void exit_room1_Button_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
}
#pragma endregion
};
}
