#pragma once

namespace Laba6Client {

	using namespace System;
	using namespace System::Threading;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::Text;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	/// 

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		Socket^ clientSocket;
		Mutex^ myMutex = gcnew Mutex(true, "mutex");
	private: System::Windows::Forms::Label^ label3;
	public:
		MyForm(void)
		{
			InitializeComponent();
			clientSocket = gcnew Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
			IPAddress^ serverIP = IPAddress::Parse("127.0.0.1");
			int serverPort = 8080;
			IPEndPoint^ serverEndPoint = gcnew IPEndPoint(serverIP, serverPort);
			clientSocket->Connect(serverEndPoint);
			myMutex->WaitOne();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			myMutex->ReleaseMutex();
			clientSocket->Close();
		}
	public: System::Windows::Forms::Label^ label1;
	protected:
	public: System::Windows::Forms::Label^ label2;
	public: System::Windows::Forms::TextBox^ textBox1;
	public: System::Windows::Forms::Label^ povarAnswer;
	public: System::Windows::Forms::Button^ exit;
	public: System::Windows::Forms::Button^ say;



	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->povarAnswer = (gcnew System::Windows::Forms::Label());
			this->exit = (gcnew System::Windows::Forms::Button());
			this->say = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(259, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Повар: Ты пришел за едой\?";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 48);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(130, 24);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Незнакомец: ";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(139, 52);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 2;
			// 
			// povarAnswer
			// 
			this->povarAnswer->AutoSize = true;
			this->povarAnswer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->povarAnswer->Location = System::Drawing::Point(12, 88);
			this->povarAnswer->Name = L"povarAnswer";
			this->povarAnswer->Size = System::Drawing::Size(71, 24);
			this->povarAnswer->TabIndex = 3;
			this->povarAnswer->Text = L"Повар:";
			this->povarAnswer->Visible = false;
			// 
			// exit
			// 
			this->exit->Location = System::Drawing::Point(16, 132);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(75, 23);
			this->exit->TabIndex = 4;
			this->exit->Text = L"Уйти";
			this->exit->UseVisualStyleBackColor = true;
			this->exit->Visible = false;
			this->exit->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// say
			// 
			this->say->Location = System::Drawing::Point(16, 48);
			this->say->Name = L"say";
			this->say->Size = System::Drawing::Size(117, 23);
			this->say->TabIndex = 5;
			this->say->Text = L"Сказать";
			this->say->UseVisualStyleBackColor = true;
			this->say->Click += gcnew System::EventHandler(this, &MyForm::say_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(89, 88);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(214, 25);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Жди своей очереди!";
			this->label3->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->ClientSize = System::Drawing::Size(348, 173);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->say);
			this->Controls->Add(this->exit);
			this->Controls->Add(this->povarAnswer);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DestroyHandle();
	}

	private: System::Void say_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			this->label3->Visible = true;
			this->label3->Visible = false;
			String^ message = this->textBox1->Text;
			array<Byte>^ buffer = Encoding::UTF8->GetBytes(message);
			clientSocket->Send(buffer);
			this->label3->Visible = true;
			this->label3->Visible = false;
			array<Byte>^ bufferFood = gcnew array<Byte>(1024);
			int bytesRead = clientSocket->Receive(bufferFood);
			String^ food = System::Text::Encoding::UTF8->GetString(bufferFood, 0, bytesRead);

			this->say->Visible = false;
			this->textBox1->Enabled = false;
			this->povarAnswer->Text = "Повар: Держи " + food;
			this->povarAnswer->Visible = true;
			this->exit->Visible = true;
		}
		catch (Exception^ e)
		{
			myMutex->ReleaseMutex();
			myMutex->WaitOne();
			Console::WriteLine("Ошибка: " + e->Message);
		}
	}
};
}
