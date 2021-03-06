#pragma once

namespace GoogleMapWithWindowsForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Net;
	using namespace System::Text;
	using namespace System::IO;

	/// <summary>
	/// Form1 的摘要
	///
	/// 警告: 如果您變更這個類別的名稱，就必須變更與這個類別所依據之所有 .resx 檔案關聯的
	///          Managed 資源編譯器工具的 'Resource File Name' 屬性。
	///          否則，這些設計工具
	///          將無法與這個表單關聯的當地語系化資源
	///          正確互動。
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::WebBrowser^  webBrowser;
	private: System::Windows::Forms::Label^  nameLabel;
	private: System::Windows::Forms::TextBox^  nameTextBox;
	private: System::Windows::Forms::Label^  addrLabel;
	private: System::Windows::Forms::TextBox^  addrTextBox;
	private: System::Windows::Forms::Button^  sendButton;
	protected: 

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->webBrowser = (gcnew System::Windows::Forms::WebBrowser());
			this->nameLabel = (gcnew System::Windows::Forms::Label());
			this->nameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->addrLabel = (gcnew System::Windows::Forms::Label());
			this->addrTextBox = (gcnew System::Windows::Forms::TextBox());
			this->sendButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// webBrowser
			// 
			this->webBrowser->Location = System::Drawing::Point(12, 12);
			this->webBrowser->MinimumSize = System::Drawing::Size(20, 20);
			this->webBrowser->Name = L"webBrowser";
			this->webBrowser->Size = System::Drawing::Size(760, 505);
			this->webBrowser->TabIndex = 0;
			//System::Environment::CurrentDirectory 為當前的目錄
			this->webBrowser->Url = (gcnew System::Uri(System::Environment::CurrentDirectory+L"/map.html", System::UriKind::Absolute));
			// 
			// nameLabel
			// 
			this->nameLabel->AutoSize = true;
			this->nameLabel->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 11));
			this->nameLabel->Location = System::Drawing::Point(8, 527);
			this->nameLabel->Name = L"nameLabel";
			this->nameLabel->Size = System::Drawing::Size(54, 19);
			this->nameLabel->TabIndex = 1;
			this->nameLabel->Text = L"姓名：";
			// 
			// nameTextBox
			// 
			this->nameTextBox->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 11));
			this->nameTextBox->Location = System::Drawing::Point(68, 523);
			this->nameTextBox->Name = L"nameTextBox";
			this->nameTextBox->Size = System::Drawing::Size(89, 27);
			this->nameTextBox->TabIndex = 2;
			// 
			// addrLabel
			// 
			this->addrLabel->AutoSize = true;
			this->addrLabel->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 11));
			this->addrLabel->Location = System::Drawing::Point(163, 526);
			this->addrLabel->Name = L"addrLabel";
			this->addrLabel->Size = System::Drawing::Size(54, 19);
			this->addrLabel->TabIndex = 3;
			this->addrLabel->Text = L"地址：";
			// 
			// addrTextBox
			// 
			this->addrTextBox->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 11));
			this->addrTextBox->Location = System::Drawing::Point(223, 523);
			this->addrTextBox->Name = L"addrTextBox";
			this->addrTextBox->Size = System::Drawing::Size(478, 27);
			this->addrTextBox->TabIndex = 4;
			// 
			// sendButton
			// 
			this->sendButton->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 11));
			this->sendButton->Location = System::Drawing::Point(707, 523);
			this->sendButton->Name = L"sendButton";
			this->sendButton->Size = System::Drawing::Size(65, 27);
			this->sendButton->TabIndex = 5;
			this->sendButton->Text = L"送出";
			this->sendButton->UseVisualStyleBackColor = true;
			this->sendButton->Click += gcnew System::EventHandler(this, &Form1::sendButton_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 562);
			this->Controls->Add(this->sendButton);
			this->Controls->Add(this->addrTextBox);
			this->Controls->Add(this->addrLabel);
			this->Controls->Add(this->nameTextBox);
			this->Controls->Add(this->nameLabel);
			this->Controls->Add(this->webBrowser);
			this->Name = L"Form1";
			this->Text = L"GoogleMapWithWindowsForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//click sendBox
	private: System::Void sendButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 String^ longitude;
				 String^ latitude;
				 if (!this->addrTextBox->Text->Empty)
				 {
					 //解析地址取得經緯度
					 WebClient^ client = gcnew WebClient;
					 Stream^ data = client->OpenRead( "http://maps.google.com/maps/geo?q="+this->addrTextBox->Text );
					 StreamReader^ reader = gcnew StreamReader( data , Encoding::UTF8);
					 String^ s = reader->ReadToEnd();
					 s = s->Substring(s->IndexOf("coordinate"));
					 array<String^>^ coordinate;
					 coordinate = s->Split(',');
					 longitude = coordinate[0]->Substring(coordinate[0]->IndexOf("[")+1);
					 latitude = coordinate[1];
					 Console::WriteLine( s );
					 data->Close();
					 reader->Close();
				 }
				 //webBrowser重載
				 String^ url = "/map.html?name="+this->nameTextBox->Text+"&longitude="+longitude+"&latitude="+latitude;
				 this->webBrowser->Url = (gcnew System::Uri(System::Environment::CurrentDirectory+url, System::UriKind::Absolute));
			 }
};
}

