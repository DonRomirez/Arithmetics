#pragma once
#include "Functions.h"
#include <msclr/marshal_cppstd.h>
namespace Arithmetics {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
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
		}
	private: System::Windows::Forms::Button^ Result_Button;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;


	private: System::Windows::Forms::Button^ Enter_button;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Parameter;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Val_Column;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->Result_Button = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Parameter = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Val_Column = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Enter_button = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// Result_Button
			// 
			this->Result_Button->Location = System::Drawing::Point(39, 186);
			this->Result_Button->Name = L"Result_Button";
			this->Result_Button->Size = System::Drawing::Size(126, 50);
			this->Result_Button->TabIndex = 0;
			this->Result_Button->Text = L"Вычислить";
			this->Result_Button->UseVisualStyleBackColor = true;
			this->Result_Button->Click += gcnew System::EventHandler(this, &MyForm::Result_Button_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(40, 22);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(391, 22);
			this->textBox1->TabIndex = 1;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(39, 52);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(473, 128);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Результат";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(7, 69);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 16);
			this->label3->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(186, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Обратная польская запись:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(253, 208);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 32);
			this->label4->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(197, 220);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Ответ:";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Parameter,
					this->Val_Column
			});
			this->dataGridView1->Location = System::Drawing::Point(546, 21);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(339, 387);
			this->dataGridView1->TabIndex = 3;
			// 
			// Parameter
			// 
			this->Parameter->HeaderText = L"Параметр";
			this->Parameter->MinimumWidth = 6;
			this->Parameter->Name = L"Parameter";
			this->Parameter->ReadOnly = true;
			this->Parameter->Width = 125;
			// 
			// Val_Column
			// 
			this->Val_Column->HeaderText = L"Значение";
			this->Val_Column->MinimumWidth = 6;
			this->Val_Column->Name = L"Val_Column";
			this->Val_Column->Width = 125;
			// 
			// Enter_button
			// 
			this->Enter_button->Location = System::Drawing::Point(437, 21);
			this->Enter_button->Name = L"Enter_button";
			this->Enter_button->Size = System::Drawing::Size(75, 23);
			this->Enter_button->TabIndex = 4;
			this->Enter_button->Text = L"Ввод";
			this->Enter_button->UseVisualStyleBackColor = true;
			this->Enter_button->Click += gcnew System::EventHandler(this, &MyForm::Enter_button_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(917, 424);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->Enter_button);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->Result_Button);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Калькулятор с параметрами";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Result_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		Functions* func = new Functions();
		String^ rpn = label3->Text;
		for (int i = 0; i < dataGridView1->RowCount; i++) {
			if (dataGridView1->Rows[0]->Cells[0]->Value == nullptr)
				break;
			String^ value = dataGridView1->Rows[i]->Cells[1]->Value->ToString();
			rpn = rpn->Replace(dataGridView1->Rows[i]->Cells[0]->Value->ToString(), value);
		}
		std::string rpn_c = msclr::interop::marshal_as<std::string>(rpn);
		std::queue<std::pair<std::string, int>> q = func->Lexical_view(rpn_c);
		double res = func->Result(q);
		label4->Text = res.ToString();

	}
private: System::Void Enter_button_Click(System::Object^ sender, System::EventArgs^ e) {
	Functions* func = new Functions();
	String^ str = textBox1->Text;
	std::queue<std::pair<std::string, int>> q = func->Lexical_view(msclr::interop::marshal_as<std::string>(str));
	std::string res = func->Reverse_Polish_notation(q);
	String^ Res = gcnew String(res.c_str());
	label3->Text = Res;
	dataGridView1->Rows->Clear();
	for (int i = 0; i < Res->Length; i++)
	{
		if ((Res[i] >= 'a') && (Res[i] <= 'z'))
		{
			int flag = 0;
			for (int j = 0; j < dataGridView1->RowCount; j++) {
			String^ check=dataGridView1->Rows[j]->Cells[0]->Value->ToString();
			if (check == Res[i].ToString())
				flag = 1;
			}
			if (flag == 1)
				continue;
			dataGridView1->Rows->Add(Res[i].ToString(), "");
		}
	}

}
};
}
