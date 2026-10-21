#include <stdio.h>
#include "lista.h"

int main(void) {
    Linear linear;
    Dinamica dinamica;

    initL(&linear);
    initD(&dinamica);

    int tipo, op, p, codigo, ok;
    Ferramenta f;

    printf("1 - Lista linear\n2 - Lista dinamica\n");
    scanf("%d", &tipo);

    if (tipo != 1 && tipo != 2) {
        printf("Opcao invalida.\n");
        return 1;
    }

    do {
        printf("\n1-Append  2-Insert  3-Pop\n");
        printf("4-Remove  5-Listar  6-Salvar\n");
        printf("7-Carregar  0-Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
        case 1:
        case 2:
            if (op == 2) {
                printf("Posicao: ");
                scanf("%d", &p);
            }

            printf("Codigo, nome (sem espacos) e quantidade: ");
            scanf("%d %49s %d",
                  &f.codigo, f.nome, &f.quantidade);

            if (tipo == 1)
                ok = (op == 1) ? appendL(&linear, f)
                               : insertL(&linear, p, f);
            else
                ok = (op == 1) ? appendD(&dinamica, f)
                               : insertD(&dinamica, p, f);

            printf(ok ? "Operacao realizada.\n"
                      : "Erro na operacao.\n");
            break;

        case 3:
            printf("Posicao: ");
            scanf("%d", &p);

            ok = (tipo == 1) ? popL(&linear, p, &f)
                             : popD(&dinamica, p, &f);

            if (ok)
                printf("Removida: %s\n", f.nome);
            else
                printf("Posicao invalida.\n");
            break;

        case 4:
            printf("Codigo: ");
            scanf("%d", &codigo);

            ok = (tipo == 1) ? removeL(&linear, codigo)
                             : removeD(&dinamica, codigo);

            printf(ok ? "Removida.\n" : "Nao encontrada.\n");
            break;

        case 5:
            if (tipo == 1) {
                for (int i = 0; i < linear.n; i++)
                    printf("%d | %s | %d\n",
                        linear.dados[i].codigo,
                        linear.dados[i].nome,
                        linear.dados[i].quantidade);
            } else {
                for (No *a = dinamica.inicio; a; a = a->prox)
                    printf("%d | %s | %d\n",
                        a->dado.codigo,
                        a->dado.nome,
                        a->dado.quantidade);
            }
            break;

        case 6:
            if (tipo == 1) salvarL(&linear);
            else salvarD(&dinamica);
            break;

        case 7:
            if (tipo == 1) carregarL(&linear);
            else carregarD(&dinamica);
            break;

        case 0:
            printf("Encerrando...\n");
            break;

        default:
            printf("Opcao invalida.\n");
        }
    } while (op != 0);

    limparD(&dinamica);
    return 0;
}
