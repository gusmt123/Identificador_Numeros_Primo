#include <iostream>
#include <vector>
#include <limits>

//função que recebe como parametro um número n e retorna todos os números primos nesse intervalo
std::vector<int> nums_primos(int n)
{
    //cria std::vector para armazenar números primo
    std::vector<int> numeros_primo;

    //loopa um número de vezes selecionado pelo usuário
    for(int i = 2; i <= n; i++) // loopa para verificar quais números são primos
    {
        bool primo = true; // Declara a variável booleana que vai definir se o número é primo

        //verifica se o número é maior que 1
        if(i > 1)
        {

            //loopa para verificar se o número é divisível por outros números
            for(int j = 2; j <= i / 2; j++)
            {

                //verifica se o número é divisível por j
                if(i % j == 0)
                {

                    primo = false; // Passa o valor de false para a variável primo como o número não é primo
                    break;  // interrompe a execução do loop

                }

            }

            //adiciona número primo ao vetor
            if(primo)
            {

                numeros_primo.push_back(i);//adiciona o número primo ao vetor
            
            }
        }

    }

    //retorna o vetor com os números primos
    return numeros_primo;

}

//função inicial do programa
int main()
{
    //constroi menu e faz input
    std::cout << "Digite ate que numero voce quer que se verifique se é primo " << std::endl;
    int num;
    std::cin >> num;

    //verifica se houve falha no input
    if(std::cin.fail())
    {
        //limpa o buffer de entrada
        std::cin.clear();
        //ignora a próxima linha
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else
    {
        // imprime os números primos
        for(const auto& n : nums_primos(num))
        {
            //printa os números primos até o limite inputado
            std::cout << n << std::endl;
        }
    }

}
