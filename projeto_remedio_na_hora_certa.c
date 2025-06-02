#include <stdio.h>

int main(void)
{
	
    char nome[50];
    float dose_mg;
    int frequencia_horas, hora_ultima_dose, hora_atual;

    printf("### REMEDIO NA HORA CERTA ###\n");
    
    printf("\nNome do medicamento: ");
    scanf("%s", nome);
    
    printf("Dose em mg: ");
    scanf("%f", &dose_mg);
    
    printf("Frequencia (a cada quantas horas?): ");
    scanf("%d", &frequencia_horas);
    
    printf("Hora da ultima dose (0-23): ");
    scanf("%d", &hora_ultima_dose);

    int proxima_hora = (hora_ultima_dose + frequencia_horas) % 24;

    printf("\n- Resumo -\n");
    printf("Medicamento: %s\n", nome);
    printf("Dose: %.2f mg\n", dose_mg);
    printf("Frequencia: a cada %d horas\n", frequencia_horas);
    
    printf("\n--- Proxima dose as: %d:00\n", proxima_hora);

    printf("\nInforme a hora atual (0-23) para verificar se a dose esta proxima: ");
    scanf("%d", &hora_atual);

    if (hora_atual == proxima_hora) {
        printf("\n--- HORA DE TOMAR SEU MEDICAMENTO AGORA!\n");
    } else if ((hora_atual < proxima_hora && (proxima_hora - hora_atual) <= 3)) {
        printf("\n--- Sua proxima dose de %s esta proxima!\n", nome);
    } else if (hora_atual > proxima_hora && hora_atual < (proxima_hora + frequencia_horas)) {
        printf("\n--- Voce ja deveria ter tomado a dose!\n");
    } else {
        printf("\n--- Nenhuma dose prevista para agora ou em breve!\n");
    }

    return 0;
}