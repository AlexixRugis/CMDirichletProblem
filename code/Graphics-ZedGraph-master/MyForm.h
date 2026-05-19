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
    private: System::Windows::Forms::DataGridView^ u_solution_grid;
    private: System::Windows::Forms::DataGridView^ v_solution_grid;
    private: System::Windows::Forms::DataGridView^ delta_solution_grid;
    private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Button^ button1;






















































































































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
            this->u_solution_grid = (gcnew System::Windows::Forms::DataGridView());
            this->v_solution_grid = (gcnew System::Windows::Forms::DataGridView());
            this->delta_solution_grid = (gcnew System::Windows::Forms::DataGridView());
            this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
            this->tabControl1->SuspendLayout();
            this->tabPage1->SuspendLayout();
            this->tableLayoutPanel1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->u_solution_grid))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->v_solution_grid))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->delta_solution_grid))->BeginInit();
            this->tableLayoutPanel2->SuspendLayout();
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
            this->tabControl1->Size = System::Drawing::Size(1540, 845);
            this->tabControl1->TabIndex = 31;
            // 
            // tabPage1
            // 
            this->tabPage1->Controls->Add(this->tableLayoutPanel1);
            this->tabPage1->Location = System::Drawing::Point(4, 25);
            this->tabPage1->Name = L"tabPage1";
            this->tabPage1->Padding = System::Windows::Forms::Padding(3);
            this->tabPage1->Size = System::Drawing::Size(1532, 816);
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
            this->tableLayoutPanel1->Controls->Add(this->u_solution_grid, 1, 0);
            this->tableLayoutPanel1->Controls->Add(this->v_solution_grid, 0, 1);
            this->tableLayoutPanel1->Controls->Add(this->delta_solution_grid, 1, 1);
            this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 0);
            this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel1->Location = System::Drawing::Point(3, 3);
            this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
            this->tableLayoutPanel1->RowCount = 2;
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
            this->tableLayoutPanel1->Size = System::Drawing::Size(1526, 810);
            this->tableLayoutPanel1->TabIndex = 0;
            // 
            // u_solution_grid
            // 
            this->u_solution_grid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->u_solution_grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->u_solution_grid->Location = System::Drawing::Point(766, 3);
            this->u_solution_grid->Name = L"u_solution_grid";
            this->u_solution_grid->RowTemplate->Height = 24;
            this->u_solution_grid->Size = System::Drawing::Size(757, 399);
            this->u_solution_grid->TabIndex = 0;
            // 
            // v_solution_grid
            // 
            this->v_solution_grid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->v_solution_grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->v_solution_grid->Location = System::Drawing::Point(3, 408);
            this->v_solution_grid->Name = L"v_solution_grid";
            this->v_solution_grid->RowTemplate->Height = 24;
            this->v_solution_grid->Size = System::Drawing::Size(757, 399);
            this->v_solution_grid->TabIndex = 1;
            // 
            // delta_solution_grid
            // 
            this->delta_solution_grid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->delta_solution_grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->delta_solution_grid->Location = System::Drawing::Point(766, 408);
            this->delta_solution_grid->Name = L"delta_solution_grid";
            this->delta_solution_grid->RowTemplate->Height = 24;
            this->delta_solution_grid->Size = System::Drawing::Size(757, 399);
            this->delta_solution_grid->TabIndex = 2;
            // 
            // tableLayoutPanel2
            // 
            this->tableLayoutPanel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->tableLayoutPanel2->ColumnCount = 1;
            this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                50)));
            this->tableLayoutPanel2->Controls->Add(this->label1, 0, 0);
            this->tableLayoutPanel2->Controls->Add(this->button1, 0, 1);
            this->tableLayoutPanel2->Location = System::Drawing::Point(3, 3);
            this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
            this->tableLayoutPanel2->RowCount = 2;
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 85.21304F)));
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.78697F)));
            this->tableLayoutPanel2->Size = System::Drawing::Size(757, 399);
            this->tableLayoutPanel2->TabIndex = 3;
            // 
            // label1
            // 
            this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(3, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(751, 340);
            this->label1->TabIndex = 0;
            this->label1->Text = L"«Для решения тестовой задачи использованы сетка с числом разбиений по x";
            // 
            // button1
            // 
            this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
            this->button1->Location = System::Drawing::Point(596, 355);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(158, 41);
            this->button1->TabIndex = 1;
            this->button1->Text = L"Решить задачу";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
            // 
            // tabPage2
            // 
            this->tabPage2->Location = System::Drawing::Point(4, 25);
            this->tabPage2->Name = L"tabPage2";
            this->tabPage2->Padding = System::Windows::Forms::Padding(3);
            this->tabPage2->Size = System::Drawing::Size(1532, 816);
            this->tabPage2->TabIndex = 1;
            this->tabPage2->Text = L"Основная задача";
            this->tabPage2->UseVisualStyleBackColor = true;
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1540, 845);
            this->Controls->Add(this->tabControl1);
            this->Margin = System::Windows::Forms::Padding(4);
            this->Name = L"MyForm";
            this->Text = L"MyForm";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->tabControl1->ResumeLayout(false);
            this->tabPage1->ResumeLayout(false);
            this->tableLayoutPanel1->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->u_solution_grid))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->v_solution_grid))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->delta_solution_grid))->EndInit();
            this->tableLayoutPanel2->ResumeLayout(false);
            this->tableLayoutPanel2->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion
    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

        DirichletProblem problem(
            (size_t)5, (size_t)6,
            -1.0, 1.0,
            -1.0, 1.0,
            func_f_test,
            func_mu1_test,
            func_mu2_test,
            func_mu3_test,
            func_mu4_test
        );

        SeidelSolver solver(1000, 1e-9);

        auto solution = solver.solve(problem);

        String^ hint = String::Format(R"(
	Для решения тестовой задачи использованы сетка с числом разбиений по x
		n = «{0}» и числом разбиений по y m = «{1}»,
		метод Зейделя, применены критерии
		остановки по точности εмет = «{2}» и по числу итераций Nmax = «{3}»
		На решение схемы(СЛАУ) затрачено итераций N = «{4}» и достигнута точность итерационного метода ε
		(N)
		= «{5}»
		Схема(СЛАУ) решена с невязкой || R(N) || = «{6}»
		для невязки СЛАУ использована норма «норма «max»;
		Тестовая задача должна быть решена с погрешностью не более ε = 0.5*1e–6;
	задача решена с погрешностью ε1 = «___»
		Максимальное отклонение точного и численного решений наблюдается в узле x = «___»; y = «___»
		В качестве начального приближения использовано
		«интерполяция по x»)",
            problem.n(), problem.m(), solver.eps(), solver.maxN(),
            solution.n, solution.eps, solution.r_norm);

        label1->Text = hint;

        FillDataGridViewFromSolution(v_solution_grid,
            problem.n(), problem.m(), problem.a(), problem.b(), problem.c(), problem.d(), solution.v, 6);
    }

    private:
        void FillDataGridView(DataGridView^ dataGridView,
            const std::vector<double>& x,
            const std::vector<double>& y,
            const std::vector<double>& solution,
            int precision) {
            if (!dataGridView || x.empty() || y.empty() || solution.empty())
                return;

            size_t n = x.size() - 1;
            size_t m = y.size() - 1;
            size_t rows = m + 1;
            size_t cols = n + 1;

            dataGridView->Rows->Clear();
            dataGridView->Columns->Clear();

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

            for (size_t j = 0; j <= m; j++)
            {
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
    };
}
