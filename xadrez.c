#include <stdio.h>

/* =======================
   1) TORRE (recursivo)
   ======================= */
/* Sobe n casas (um passo por chamada) */
void torre_cima_rec(int n) {
    if (n <= 0) return;
    printf("Cima\n");
    torre_cima_rec(n - 1);
}

/* Vai n casas para a direita (um passo por chamada) */
void torre_direita_rec(int n) {
    if (n <= 0) return;
    printf("Direita\n");
    torre_direita_rec(n - 1);
}

/* =======================
   2) BISPO (recursivo)
   ======================= */
/* Diagonal: para cada casa, 1 passo vertical + 1 passo horizontal.
   Aqui usamos “Cima + Direita” para simplificar (ou troque por "Baixo/Esquerda"). */
void bispo_diag_cima_direita_rec(int n) {
    if (n <= 0) return;
    printf("Cima\n");
    printf("Direita\n");
    bispo_diag_cima_direita_rec(n - 1);
}

/* ================================
   3) RAINHA (recursivo)
   ================================ */
/* Exemplo simples: a rainha anda como torre e como bispo.
   Aqui, primeiro anda 'h' casas para a esquerda (torre),
   depois 'd' casas em diagonal (cima+direita). */
void rainha_esquerda_rec(int h) {
    if (h <= 0) return;
    printf("Esquerda\n");
    rainha_esquerda_rec(h - 1);
}
void rainha_diag_cima_direita_rec(int d) {
    if (d <= 0) return;
    printf("Cima\n");
    printf("Direita\n");
    rainha_diag_cima_direita_rec(d - 1);
}

/* ==============================================
   4) CAVALO (loops aninhados + continue/break)
   ==============================================
*/
void cavalo_loops_complexos(int movimentos, int linha_inicial, int coluna_inicial) {
    int linha = linha_inicial;
    int coluna = coluna_inicial;

    for (int m = 1; m <= movimentos; m++) {
        /* Dois passos para cima (loop interno 1) */
        for (int up = 1; up <= 2; up++) {
            if (linha <= 1) {
                /* Não dá pra subir: interrompe esse movimento */
                break; /* sai do loop 'up' */
            }
            linha--;
            printf("Cima\n");
        }

        /* Um passo para a direita (loop interno 2) */
        for (int right = 1; right <= 1; right++) {
            if (coluna >= 8) {
                /* Já está na borda direita: não anda para a direita neste movimento */
                continue; /* pula a impressão da Direita e segue */
            }
            coluna++;
            printf("Direita\n");
        }

        /* (Opcional) linha em branco separando cada “L” do cavalo
           (comentado para manter exatamente o formato de uma direção por linha)
        */
        /* printf("\n"); */
    }
}

/* ======================================================
   5) BISPO COM LOOPS ANINHADOS (além da versão recursiva)
   ======================================================
*/
void bispo_loops_aninhados(int passos) {
    for (int v = 1; v <= passos; v++) {
        /* vertical (externo) */
        printf("Cima\n");
        /* horizontal (interno) — aqui 1 vez por passo para compor a diagonal */
        for (int h = 1; h <= 1; h++) {
            printf("Direita\n");
        }
    }
}

int main(void) {
    /* ===========================
       Configurações (sem input)
       =========================== */
    /* Torre: quantas casas para cada direção recursiva */
    int torre_sobe = 3;
    int torre_direita = 2;

    /* Bispo: diagonal (recursão) e diagonal (loops) */
    int bispo_passos_rec = 3;
    int bispo_passos_loops = 2;

    /* Rainha: horizontal para esquerda e diagonal cima+direita */
    int rainha_esq = 2;
    int rainha_diag = 3;

    /* Cavalo: número de movimentos em L e posição inicial no tabuleiro (1..8) */
    int cavalo_movimentos = 3;
    int cavalo_linha_inicial = 4;
    int cavalo_coluna_inicial = 4;

    /* ===========================
       TORRE (recursivo)
       =========================== */
    printf("=== TORRE (recursivo) ===\n");
    torre_cima_rec(torre_sobe);      /* Cima n vezes */
    torre_direita_rec(torre_direita);/* Direita n vezes */
    printf("\n");

    /* ===========================
       BISPO (recursivo)
       =========================== */
    printf("=== BISPO (recursivo) ===\n");
    bispo_diag_cima_direita_rec(bispo_passos_rec); /* (Cima + Direita) por passo */
    printf("\n");

    /* =====================================
       BISPO (loops aninhados: V -> H)
       ===================================== */
    printf("=== BISPO (loops aninhados) ===\n");
    bispo_loops_aninhados(bispo_passos_loops);
    printf("\n");

    /* ===========================
       RAINHA (recursivo)
       =========================== */
    printf("=== RAINHA (recursivo) ===\n");
    rainha_esquerda_rec(rainha_esq);             /* Esquerda h vezes */
    rainha_diag_cima_direita_rec(rainha_diag);   /* (Cima + Direita) d vezes */
    printf("\n");

    /* ==========================================
       CAVALO (loops aninhados + continue/break)
       ========================================== */
    printf("=== CAVALO (loops aninhados) ===\n");
    cavalo_loops_complexos(cavalo_movimentos, cavalo_linha_inicial, cavalo_coluna_inicial);
    printf("\n");

    return 0;
}
