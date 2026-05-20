#pragma once

#include <cmath>
#include <climits>
#include <cfloat>
#include <string>
#include "Functions.h"
#include "Problem.h"
#include "SeidelSolver.h"
#include "SORSolver.h"

namespace Graph {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace ZedGraph;
    using namespace CMDirichlet;

    /// <summary>
    /// Summary for MyForm
    /// </summary>
    public ref class MyForm : public System::Windows::Forms::Form {
    public:
        MyForm(void) {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~MyForm() {
            if (components) {
                delete components;
            }
        }


















































    private: System::Windows::Forms::TabControl^ tabControl1;
    private: System::Windows::Forms::TabPage^ tabPage1;
    private: System::Windows::Forms::TabPage^ tabPage2;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;



    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::GroupBox^ problem2_groupbox;


    private: System::Windows::Forms::DataGridView^ u_solution_grid;
    private: System::Windows::Forms::GroupBox^ problem1_groupbox;

    private: System::Windows::Forms::DataGridView^ v_solution_grid;
    private: System::Windows::Forms::GroupBox^ problem_diff_groupbox;

    private: System::Windows::Forms::DataGridView^ delta_solution_grid;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel4;
    private: System::Windows::Forms::TextBox^ a_textbox;
    private: System::Windows::Forms::TextBox^ b_textbox;

    private: System::Windows::Forms::TextBox^ d_textbox;
    private: System::Windows::Forms::TextBox^ c_textbox;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::TextBox^ n_textbox;
    private: System::Windows::Forms::TextBox^ m_textbox;
    private: System::Windows::Forms::TextBox^ nmax_textbox;
    private: System::Windows::Forms::TextBox^ epsn_textbox;




    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::Label^ label8;
    private: System::Windows::Forms::Label^ label9;




    private: System::Windows::Forms::TextBox^ w_textbox;

    private: System::Windows::Forms::Label^ label10;
    private: System::Windows::Forms::Label^ label11;
    private: System::Windows::Forms::Label^ label12;
    private: System::Windows::Forms::ComboBox^ method_combobox;
    private: System::Windows::Forms::ComboBox^ problem_combobox;





























































































































    protected:
    private: System::ComponentModel::IContainer^ components;

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>


#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void) {
            this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
            this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
            this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->a_textbox = (gcnew System::Windows::Forms::TextBox());
            this->b_textbox = (gcnew System::Windows::Forms::TextBox());
            this->d_textbox = (gcnew System::Windows::Forms::TextBox());
            this->c_textbox = (gcnew System::Windows::Forms::TextBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->n_textbox = (gcnew System::Windows::Forms::TextBox());
            this->m_textbox = (gcnew System::Windows::Forms::TextBox());
            this->nmax_textbox = (gcnew System::Windows::Forms::TextBox());
            this->epsn_textbox = (gcnew System::Windows::Forms::TextBox());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->w_textbox = (gcnew System::Windows::Forms::TextBox());
            this->label10 = (gcnew System::Windows::Forms::Label());
            this->label11 = (gcnew System::Windows::Forms::Label());
            this->label12 = (gcnew System::Windows::Forms::Label());
            this->method_combobox = (gcnew System::Windows::Forms::ComboBox());
            this->problem_combobox = (gcnew System::Windows::Forms::ComboBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->problem2_groupbox = (gcnew System::Windows::Forms::GroupBox());
            this->u_solution_grid = (gcnew System::Windows::Forms::DataGridView());
            this->problem1_groupbox = (gcnew System::Windows::Forms::GroupBox());
            this->v_solution_grid = (gcnew System::Windows::Forms::DataGridView());
            this->problem_diff_groupbox = (gcnew System::Windows::Forms::GroupBox());
            this->delta_solution_grid = (gcnew System::Windows::Forms::DataGridView());
            this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
            this->tabControl1->SuspendLayout();
            this->tabPage1->SuspendLayout();
            this->tableLayoutPanel1->SuspendLayout();
            this->tableLayoutPanel2->SuspendLayout();
            this->tableLayoutPanel3->SuspendLayout();
            this->tableLayoutPanel4->SuspendLayout();
            this->problem2_groupbox->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->u_solution_grid))->BeginInit();
            this->problem1_groupbox->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->v_solution_grid))->BeginInit();
            this->problem_diff_groupbox->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->delta_solution_grid))->BeginInit();
            this->SuspendLayout();
            // 
            // tabControl1
            // 
            this->tabControl1->Controls->Add(this->tabPage1);
            this->tabControl1->Controls->Add(this->tabPage2);
            this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tabControl1->Location = System::Drawing::Point(0, 0);
            this->tabControl1->Name = L"tabControl1";
            this->tabControl1->SelectedIndex = 0;
            this->tabControl1->Size = System::Drawing::Size(1802, 896);
            this->tabControl1->TabIndex = 31;
            // 
            // tabPage1
            // 
            this->tabPage1->Controls->Add(this->tableLayoutPanel1);
            this->tabPage1->Location = System::Drawing::Point(4, 25);
            this->tabPage1->Name = L"tabPage1";
            this->tabPage1->Padding = System::Windows::Forms::Padding(3);
            this->tabPage1->Size = System::Drawing::Size(1794, 867);
            this->tabPage1->TabIndex = 0;
            this->tabPage1->Text = L"Тестовая задача";
            this->tabPage1->UseVisualStyleBackColor = true;
            // 
            // tableLayoutPanel1
            // 
            this->tableLayoutPanel1->ColumnCount = 2;
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                50)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                50)));
            this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 0);
            this->tableLayoutPanel1->Controls->Add(this->problem2_groupbox, 1, 0);
            this->tableLayoutPanel1->Controls->Add(this->problem1_groupbox, 0, 1);
            this->tableLayoutPanel1->Controls->Add(this->problem_diff_groupbox, 1, 1);
            this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel1->Location = System::Drawing::Point(3, 3);
            this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
            this->tableLayoutPanel1->RowCount = 2;
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tableLayoutPanel1->Size = System::Drawing::Size(1788, 861);
            this->tableLayoutPanel1->TabIndex = 0;
            // 
            // tableLayoutPanel2
            // 
            this->tableLayoutPanel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->tableLayoutPanel2->ColumnCount = 1;
            this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                50)));
            this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel3, 0, 1);
            this->tableLayoutPanel2->Controls->Add(this->label1, 0, 0);
            this->tableLayoutPanel2->Location = System::Drawing::Point(3, 3);
            this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
            this->tableLayoutPanel2->RowCount = 2;
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 72.16982F)));
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 27.83019F)));
            this->tableLayoutPanel2->Size = System::Drawing::Size(888, 424);
            this->tableLayoutPanel2->TabIndex = 3;
            // 
            // tableLayoutPanel3
            // 
            this->tableLayoutPanel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->tableLayoutPanel3->ColumnCount = 2;
            this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                77.32426F)));
            this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                22.67574F)));
            this->tableLayoutPanel3->Controls->Add(this->button1, 1, 0);
            this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel4, 0, 0);
            this->tableLayoutPanel3->Location = System::Drawing::Point(3, 309);
            this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
            this->tableLayoutPanel3->RowCount = 1;
            this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
            this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 112)));
            this->tableLayoutPanel3->Size = System::Drawing::Size(882, 112);
            this->tableLayoutPanel3->TabIndex = 1;
            // 
            // button1
            // 
            this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
            this->button1->Location = System::Drawing::Point(731, 61);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(148, 48);
            this->button1->TabIndex = 0;
            this->button1->Text = L"Решить задачу";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
            // 
            // tableLayoutPanel4
            // 
            this->tableLayoutPanel4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->tableLayoutPanel4->ColumnCount = 6;
            this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                15.25926F)));
            this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                4.888889F)));
            this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                16)));
            this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                23.7037F)));
            this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                19.99805F)));
            this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                19.99805F)));
            this->tableLayoutPanel4->Controls->Add(this->a_textbox, 0, 0);
            this->tableLayoutPanel4->Controls->Add(this->b_textbox, 0, 1);
            this->tableLayoutPanel4->Controls->Add(this->d_textbox, 0, 3);
            this->tableLayoutPanel4->Controls->Add(this->c_textbox, 0, 2);
            this->tableLayoutPanel4->Controls->Add(this->label2, 1, 0);
            this->tableLayoutPanel4->Controls->Add(this->label3, 1, 1);
            this->tableLayoutPanel4->Controls->Add(this->label4, 1, 2);
            this->tableLayoutPanel4->Controls->Add(this->label5, 1, 3);
            this->tableLayoutPanel4->Controls->Add(this->n_textbox, 2, 0);
            this->tableLayoutPanel4->Controls->Add(this->m_textbox, 2, 1);
            this->tableLayoutPanel4->Controls->Add(this->nmax_textbox, 2, 2);
            this->tableLayoutPanel4->Controls->Add(this->epsn_textbox, 2, 3);
            this->tableLayoutPanel4->Controls->Add(this->label6, 3, 0);
            this->tableLayoutPanel4->Controls->Add(this->label7, 3, 1);
            this->tableLayoutPanel4->Controls->Add(this->label8, 3, 2);
            this->tableLayoutPanel4->Controls->Add(this->label9, 3, 3);
            this->tableLayoutPanel4->Controls->Add(this->w_textbox, 4, 1);
            this->tableLayoutPanel4->Controls->Add(this->label10, 5, 0);
            this->tableLayoutPanel4->Controls->Add(this->label11, 5, 1);
            this->tableLayoutPanel4->Controls->Add(this->label12, 5, 2);
            this->tableLayoutPanel4->Controls->Add(this->method_combobox, 4, 0);
            this->tableLayoutPanel4->Controls->Add(this->problem_combobox, 4, 2);
            this->tableLayoutPanel4->Location = System::Drawing::Point(3, 3);
            this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
            this->tableLayoutPanel4->RowCount = 4;
            this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
            this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
            this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
            this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
            this->tableLayoutPanel4->Size = System::Drawing::Size(675, 106);
            this->tableLayoutPanel4->TabIndex = 1;
            // 
            // a_textbox
            // 
            this->a_textbox->Location = System::Drawing::Point(3, 3);
            this->a_textbox->Name = L"a_textbox";
            this->a_textbox->Size = System::Drawing::Size(93, 22);
            this->a_textbox->TabIndex = 0;
            // 
            // b_textbox
            // 
            this->b_textbox->Location = System::Drawing::Point(3, 29);
            this->b_textbox->Name = L"b_textbox";
            this->b_textbox->Size = System::Drawing::Size(93, 22);
            this->b_textbox->TabIndex = 1;
            // 
            // d_textbox
            // 
            this->d_textbox->Location = System::Drawing::Point(3, 81);
            this->d_textbox->Name = L"d_textbox";
            this->d_textbox->Size = System::Drawing::Size(93, 22);
            this->d_textbox->TabIndex = 3;
            // 
            // c_textbox
            // 
            this->c_textbox->Location = System::Drawing::Point(3, 55);
            this->c_textbox->Name = L"c_textbox";
            this->c_textbox->Size = System::Drawing::Size(93, 22);
            this->c_textbox->TabIndex = 4;
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(106, 0);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(15, 16);
            this->label2->TabIndex = 5;
            this->label2->Text = L"a";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(106, 26);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(15, 16);
            this->label3->TabIndex = 6;
            this->label3->Text = L"b";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(106, 52);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(14, 16);
            this->label4->TabIndex = 7;
            this->label4->Text = L"c";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(106, 78);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(15, 16);
            this->label5->TabIndex = 8;
            this->label5->Text = L"d";
            // 
            // n_textbox
            // 
            this->n_textbox->Location = System::Drawing::Point(139, 3);
            this->n_textbox->Name = L"n_textbox";
            this->n_textbox->Size = System::Drawing::Size(100, 22);
            this->n_textbox->TabIndex = 9;
            // 
            // m_textbox
            // 
            this->m_textbox->Location = System::Drawing::Point(139, 29);
            this->m_textbox->Name = L"m_textbox";
            this->m_textbox->Size = System::Drawing::Size(100, 22);
            this->m_textbox->TabIndex = 10;
            // 
            // nmax_textbox
            // 
            this->nmax_textbox->Location = System::Drawing::Point(139, 55);
            this->nmax_textbox->Name = L"nmax_textbox";
            this->nmax_textbox->Size = System::Drawing::Size(100, 22);
            this->nmax_textbox->TabIndex = 11;
            // 
            // epsn_textbox
            // 
            this->epsn_textbox->Location = System::Drawing::Point(139, 81);
            this->epsn_textbox->Name = L"epsn_textbox";
            this->epsn_textbox->Size = System::Drawing::Size(100, 22);
            this->epsn_textbox->TabIndex = 12;
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Location = System::Drawing::Point(247, 0);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(14, 16);
            this->label6->TabIndex = 13;
            this->label6->Text = L"n";
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Location = System::Drawing::Point(247, 26);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(18, 16);
            this->label7->TabIndex = 14;
            this->label7->Text = L"m";
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->Location = System::Drawing::Point(247, 52);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(42, 16);
            this->label8->TabIndex = 15;
            this->label8->Text = L"Nmax";
            // 
            // label9
            // 
            this->label9->AutoSize = true;
            this->label9->Location = System::Drawing::Point(247, 78);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(47, 16);
            this->label9->TabIndex = 16;
            this->label9->Text = L"eps_N";
            // 
            // w_textbox
            // 
            this->w_textbox->Location = System::Drawing::Point(407, 29);
            this->w_textbox->Name = L"w_textbox";
            this->w_textbox->Size = System::Drawing::Size(100, 22);
            this->w_textbox->TabIndex = 19;
            // 
            // label10
            // 
            this->label10->AutoSize = true;
            this->label10->Location = System::Drawing::Point(542, 0);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(108, 16);
            this->label10->TabIndex = 20;
            this->label10->Text = L"Метод решения";
            // 
            // label11
            // 
            this->label11->AutoSize = true;
            this->label11->Location = System::Drawing::Point(542, 26);
            this->label11->Name = L"label11";
            this->label11->Size = System::Drawing::Size(16, 16);
            this->label11->TabIndex = 21;
            this->label11->Text = L"w";
            // 
            // label12
            // 
            this->label12->AutoSize = true;
            this->label12->Location = System::Drawing::Point(542, 52);
            this->label12->Name = L"label12";
            this->label12->Size = System::Drawing::Size(56, 16);
            this->label12->TabIndex = 22;
            this->label12->Text = L"Задача";
            // 
            // method_combobox
            // 
            this->method_combobox->FormattingEnabled = true;
            this->method_combobox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Зейделя", L"МВР" });
            this->method_combobox->Location = System::Drawing::Point(407, 3);
            this->method_combobox->Name = L"method_combobox";
            this->method_combobox->Size = System::Drawing::Size(121, 24);
            this->method_combobox->TabIndex = 23;
            // 
            // problem_combobox
            // 
            this->problem_combobox->FormattingEnabled = true;
            this->problem_combobox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Тестовая", L"Основная" });
            this->problem_combobox->Location = System::Drawing::Point(407, 55);
            this->problem_combobox->Name = L"problem_combobox";
            this->problem_combobox->Size = System::Drawing::Size(121, 24);
            this->problem_combobox->TabIndex = 24;
            // 
            // label1
            // 
            this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(3, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(882, 306);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Здесь появится справка о решении задачи";
            // 
            // problem2_groupbox
            // 
            this->problem2_groupbox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->problem2_groupbox->Controls->Add(this->u_solution_grid);
            this->problem2_groupbox->Location = System::Drawing::Point(897, 3);
            this->problem2_groupbox->Name = L"problem2_groupbox";
            this->problem2_groupbox->Size = System::Drawing::Size(888, 424);
            this->problem2_groupbox->TabIndex = 4;
            this->problem2_groupbox->TabStop = false;
            this->problem2_groupbox->Text = L"u*(x,y)";
            // 
            // u_solution_grid
            // 
            this->u_solution_grid->BackgroundColor = System::Drawing::SystemColors::ControlLight;
            this->u_solution_grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->u_solution_grid->Dock = System::Windows::Forms::DockStyle::Fill;
            this->u_solution_grid->Location = System::Drawing::Point(3, 18);
            this->u_solution_grid->Name = L"u_solution_grid";
            this->u_solution_grid->RowHeadersWidth = 51;
            this->u_solution_grid->RowTemplate->Height = 24;
            this->u_solution_grid->Size = System::Drawing::Size(882, 403);
            this->u_solution_grid->TabIndex = 0;
            // 
            // problem1_groupbox
            // 
            this->problem1_groupbox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->problem1_groupbox->Controls->Add(this->v_solution_grid);
            this->problem1_groupbox->Location = System::Drawing::Point(3, 433);
            this->problem1_groupbox->Name = L"problem1_groupbox";
            this->problem1_groupbox->Size = System::Drawing::Size(888, 425);
            this->problem1_groupbox->TabIndex = 5;
            this->problem1_groupbox->TabStop = false;
            this->problem1_groupbox->Text = L"v*(x, y)";
            // 
            // v_solution_grid
            // 
            this->v_solution_grid->BackgroundColor = System::Drawing::SystemColors::ControlLight;
            this->v_solution_grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->v_solution_grid->Dock = System::Windows::Forms::DockStyle::Fill;
            this->v_solution_grid->Location = System::Drawing::Point(3, 18);
            this->v_solution_grid->Name = L"v_solution_grid";
            this->v_solution_grid->RowHeadersWidth = 51;
            this->v_solution_grid->RowTemplate->Height = 24;
            this->v_solution_grid->Size = System::Drawing::Size(882, 404);
            this->v_solution_grid->TabIndex = 0;
            // 
            // problem_diff_groupbox
            // 
            this->problem_diff_groupbox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->problem_diff_groupbox->Controls->Add(this->delta_solution_grid);
            this->problem_diff_groupbox->Location = System::Drawing::Point(897, 433);
            this->problem_diff_groupbox->Name = L"problem_diff_groupbox";
            this->problem_diff_groupbox->Size = System::Drawing::Size(888, 425);
            this->problem_diff_groupbox->TabIndex = 6;
            this->problem_diff_groupbox->TabStop = false;
            this->problem_diff_groupbox->Text = L"u* - v*";
            // 
            // delta_solution_grid
            // 
            this->delta_solution_grid->BackgroundColor = System::Drawing::SystemColors::ControlLight;
            this->delta_solution_grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->delta_solution_grid->Dock = System::Windows::Forms::DockStyle::Fill;
            this->delta_solution_grid->Location = System::Drawing::Point(3, 18);
            this->delta_solution_grid->Name = L"delta_solution_grid";
            this->delta_solution_grid->RowHeadersWidth = 51;
            this->delta_solution_grid->RowTemplate->Height = 24;
            this->delta_solution_grid->Size = System::Drawing::Size(882, 404);
            this->delta_solution_grid->TabIndex = 0;
            // 
            // tabPage2
            // 
            this->tabPage2->Location = System::Drawing::Point(4, 25);
            this->tabPage2->Name = L"tabPage2";
            this->tabPage2->Padding = System::Windows::Forms::Padding(3);
            this->tabPage2->Size = System::Drawing::Size(1794, 867);
            this->tabPage2->TabIndex = 1;
            this->tabPage2->Text = L"Основная задача";
            this->tabPage2->UseVisualStyleBackColor = true;
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1802, 896);
            this->Controls->Add(this->tabControl1);
            this->Margin = System::Windows::Forms::Padding(4);
            this->Name = L"MyForm";
            this->Text = L"MyForm";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->tabControl1->ResumeLayout(false);
            this->tabPage1->ResumeLayout(false);
            this->tableLayoutPanel1->ResumeLayout(false);
            this->tableLayoutPanel2->ResumeLayout(false);
            this->tableLayoutPanel2->PerformLayout();
            this->tableLayoutPanel3->ResumeLayout(false);
            this->tableLayoutPanel4->ResumeLayout(false);
            this->tableLayoutPanel4->PerformLayout();
            this->problem2_groupbox->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->u_solution_grid))->EndInit();
            this->problem1_groupbox->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->v_solution_grid))->EndInit();
            this->problem_diff_groupbox->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->delta_solution_grid))->EndInit();
            this->ResumeLayout(false);

        }
#pragma endregion
    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
        a_textbox->Text = "-1.0";
        b_textbox->Text = "1.0";
        c_textbox->Text = "-1.0";
        d_textbox->Text = "1.0";

        epsn_textbox->Text = "1e-9";

        n_textbox->Text = "10";
        m_textbox->Text = "10";

        nmax_textbox->Text = "20000";

        w_textbox->Text = "1.8";
        method_combobox->SelectedIndex = 0;
        problem_combobox->SelectedIndex = 0;
    }
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

        a_textbox->Text = a_textbox->Text->Replace(".", ",");
        b_textbox->Text = b_textbox->Text->Replace(".", ",");
        c_textbox->Text = c_textbox->Text->Replace(".", ",");
        d_textbox->Text = d_textbox->Text->Replace(".", ",");
        epsn_textbox->Text = epsn_textbox->Text->Replace(".", ",");
        w_textbox->Text = w_textbox->Text->Replace(".", ",");

        double a = Convert::ToDouble(a_textbox->Text);
        double b = Convert::ToDouble(b_textbox->Text);
        double c = Convert::ToDouble(c_textbox->Text);
        double d = Convert::ToDouble(d_textbox->Text);

        double epsn = Convert::ToDouble(epsn_textbox->Text);

        double w = Convert::ToDouble(w_textbox->Text);

        size_t n = Convert::ToUInt64(n_textbox->Text);
        size_t m = Convert::ToUInt64(m_textbox->Text);

        size_t nmax = Convert::ToUInt64(nmax_textbox->Text);

        if (problem_combobox->SelectedIndex == 0) {
            DirichletProblem problem(
                n, m, a, b, c, d,
                func_f_test,
                func_mu1_test,
                func_mu2_test,
                func_mu3_test,
                func_mu4_test
            );

            const auto solution = Solve(problem, nmax, epsn, w);
            const auto& v = solution.v;

            std::vector<double> u(solution.v.size(), 0.0);
            std::vector<double> diff_u_v(solution.v.size(), 0.0);

            for (size_t j = 0; j <= problem.m(); j++) {
                for (size_t i = 0; i <= problem.n(); i++) {
                    size_t index = j * (problem.n() + 1) + i;
                    u[index] = func_u_test(problem.x(i), problem.y(j));
                }
            }

            double eps_1 = 0.0;
            double eps_x = 0.0;
            double eps_y = 0.0;

            for (size_t j = 0; j <= problem.m(); j++) {
                for (size_t i = 0; i <= problem.n(); i++) {
                    size_t index = j * (problem.n() + 1) + i;
                    diff_u_v[index] = u[index] - v[index];

                    if (abs(diff_u_v[index]) > eps_1) {
                        eps_1 = abs(diff_u_v[index]);
                        eps_x = problem.x(i);
                        eps_y = problem.y(j);
                    }
                }
            }

            String^ hint = String::Format(R"(
	Для решения тестовой задачи использованы сетка с числом разбиений по x
		n = «{0}» и числом разбиений по y m = «{1}»,
		метод Зейделя, применены критерии
		остановки по точности eps_мет = «{2}» и по числу итераций Nmax = «{3}»
		На решение схемы(СЛАУ) затрачено итераций N = «{4}» и достигнута точность итерационного метода ε
		(N)
		= «{5}»
		Схема(СЛАУ) решена с невязкой || R(N) || = «{6}»
		для невязки СЛАУ использована норма «норма «max»;
	Задача решена с погрешностью eps_1 = «{7}»
		Максимальное отклонение точного и численного решений наблюдается в узле x = «{8}»; y = «{9}»
		В качестве начального приближения использовано
		«интерполяция по x»)",
                problem.n(), problem.m(), epsn, nmax,
                solution.n, solution.eps, solution.r_norm,
                eps_1, eps_x, eps_y);

            label1->Text = hint;

            problem1_groupbox->Text = "v*(x,y)";
            FillDataGridViewFromSolution(v_solution_grid,
                problem.n(), problem.m(), problem.a(), problem.b(), problem.c(), problem.d(), v, 6);
            problem2_groupbox->Text = "u*(x,y)";
            FillDataGridViewFromSolution(u_solution_grid,
                problem.n(), problem.m(), problem.a(), problem.b(), problem.c(), problem.d(), u, 6);
            problem_diff_groupbox->Text = "u* - v*";
            FillDataGridViewFromSolution(delta_solution_grid,
                problem.n(), problem.m(), problem.a(), problem.b(), problem.c(), problem.d(), diff_u_v, 6);
        }
        else {
            DirichletProblem problem(
                n, m, a, b, c, d,
                func_f_main,
                func_mu1_main,
                func_mu2_main,
                func_mu3_main,
                func_mu4_main
            );

            DirichletProblem problem2(
                2 * n, 2 * m, a, b, c, d,
                func_f_main,
                func_mu1_main,
                func_mu2_main,
                func_mu3_main,
                func_mu4_main
            );

            const auto solution = Solve(problem, nmax, epsn, w);
            const auto& v = solution.v;
            const auto solution2 = Solve(problem2, nmax, epsn, w);
            const auto& v2 = solution2.v;

            std::vector<double> diff_v_v2(solution.v.size(), 0.0);

            double eps_1 = 0.0;
            double eps_x = 0.0;
            double eps_y = 0.0;

            for (size_t j = 0; j <= problem.m(); j++) {
                for (size_t i = 0; i <= problem.n(); i++) {
                    size_t index = j * (problem.n() + 1) + i;
                    size_t index2 = 2 * j * (2 * problem.n() + 1) + 2 * i;
                    diff_v_v2[index] = v[index] - v2[index2];

                    if (abs(diff_v_v2[index]) > eps_1) {
                        eps_1 = abs(diff_v_v2[index]);
                        eps_x = problem.x(i);
                        eps_y = problem.y(j);
                    }
                }
            }

            String^ hint = String::Format(R"(Для решения основной задачи использована сетка с числом разбиений по x
n = «{0}» и числом разбиений по y m = «{1}», применены критерии остановки по точности eps_мет = «{2}»
и по числу итераций Nmax =«{3}»
На решение схемы (СЛАУ) затрачено итераций N = «{4}» и достигнута точность итерационного метода eps_N = «{5}»
Схема (СЛАУ) решена с невязкой || R(N)|| = «{6}»
использована норма «норма «max»
Для контроля точности решения использована сетка с половинным шагом
На решение задачи (СЛАУ) затрачено итераций N2 =«{7}» и достигнута точность итерационного метода eps_N2 = «{8}»
Схема (СЛАУ) на сетке с половинным шагом решена с невязкой
|| R(N2) || = «{9}»
использована норма «норма «max»
Задача решена с точностью eps2 =«{10}»
Максимальное отклонение численных решений на основной сетке и сетке с
половинным шагом наблюдается в узле x=«{11}»; y=«{12}»
В качестве начального приближения на основной и дополнительной сетке использовано
«интерполяция по x»)",
                problem.n(), problem.m(), epsn, nmax,
                solution.n, solution.eps, solution.r_norm,
                solution2.n, solution2.eps, solution2.r_norm,
                eps_1, eps_x, eps_y);

            label1->Text = hint;

            problem1_groupbox->Text = "v(x,y)";
            FillDataGridViewFromSolution(v_solution_grid,
                problem.n(), problem.m(), problem.a(), problem.b(), problem.c(), problem.d(), v, 6);
            problem2_groupbox->Text = "v2(x,y)";
            FillDataGridViewFromSolution(u_solution_grid,
                problem.n(), problem.m(), problem.a(), problem.b(), problem.c(), problem.d(), v2, 6);
            problem_diff_groupbox->Text = "v - v2";
            FillDataGridViewFromSolution(delta_solution_grid,
                problem.n(), problem.m(), problem.a(), problem.b(), problem.c(), problem.d(), diff_v_v2, 6);
        }
    }

    private:
        void FillDataGridView(DataGridView^ dataGridView,
            const std::vector<double>& x,
            const std::vector<double>& y,
            const std::vector<double>& solution,
            int precision) {

            if (!dataGridView || x.empty() || y.empty() || solution.empty())
                return;

            dataGridView->SuspendLayout();
            dataGridView->Visible = false;

            size_t n = x.size() - 1;
            size_t m = y.size() - 1;
            size_t rows = m + 1;
            size_t cols = n + 1;

            dataGridView->Rows->Clear();
            dataGridView->Columns->Clear();

            dataGridView->RowHeadersVisible = false;
            dataGridView->AllowUserToAddRows = false;
            dataGridView->AllowUserToDeleteRows = false;
            dataGridView->ReadOnly = true;
            dataGridView->RowHeadersWidth = 60;
            dataGridView->ColumnHeadersHeight = 40;

            DataGridViewTextBoxColumn^ headerCol = gcnew DataGridViewTextBoxColumn();
            headerCol->Name = L"Header";
            headerCol->HeaderText = L"x / y";
            headerCol->Width = 60;
            headerCol->ReadOnly = true;
            dataGridView->Columns->Add(headerCol);

            for (size_t i = 0; i <= n; i++) {
                DataGridViewTextBoxColumn^ col = gcnew DataGridViewTextBoxColumn();
                col->Name = String::Format("x_{0}", i);
                col->HeaderText = String::Format("x_{0} = {1}", i, x[i].ToString());
                col->Width = 90;
                col->ReadOnly = true;
                dataGridView->Columns->Add(col);
            }

            for (size_t j = 0; j <= m; j++) {
                DataGridViewRow^ row = gcnew DataGridViewRow();
                row->Height = 25;

                dataGridView->Rows->Add();

                dataGridView->Rows[j]->Cells[0]->Value = String::Format("y_{0} = {1}", j, y[j].ToString());

                for (size_t i = 0; i <= n; i++) {
                    DataGridViewTextBoxCell^ cell = gcnew DataGridViewTextBoxCell();
                    double value = solution[j * (n + 1) + i];
                    dataGridView->Rows[j]->Cells[i + 1]->Value = value.ToString();
                }

            }

            dataGridView->AutoResizeColumns(DataGridViewAutoSizeColumnsMode::AllCells);
            dataGridView->AutoResizeRows(DataGridViewAutoSizeRowsMode::AllCells);

            dataGridView->Visible = true;
            dataGridView->ResumeLayout();
            dataGridView->Refresh();
        }

        void FillDataGridViewFromSolution(DataGridView^ dataGridView,
            size_t n, size_t m,
            double a, double b, double c, double d,
            const std::vector<double>& solution,
            int precision) {
            std::vector<double> x(n + 1);
            std::vector<double> y(m + 1);

            double h = (b - a) / n;
            double k = (d - c) / m;

            for (size_t i = 0; i <= n; i++)
                x[i] = a + i * h;

            for (size_t j = 0; j <= m; j++)
                y[j] = c + j * k;

            FillDataGridView(dataGridView, x, y, solution, precision);
        }

        DiricletProblemSolution Solve(const DirichletProblem& problem, size_t nmax, double epsn, double w) {
            DiricletProblemSolution solution;
            if (method_combobox->SelectedIndex == 0) {
                SeidelSolver solver(nmax, epsn);
                solution = solver.solve(problem);
            }
            else {
                SORSolver solver(nmax, epsn, w);
                solution = solver.solve(problem);
            }

            return solution;
        }
    };
}
