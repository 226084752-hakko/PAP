#include <stdio.h>
#include "config.h"
#include "assets.h"
#include "utilities.h"

typedef struct
{
    int id;
    char name[50];
    double value;
} Asset;

static Asset assets[MAX_ASSETS];
static int assetCount = 0;

void addAsset(void)
{
    if (assetCount == MAX_ASSETS)
    {
        printf("Asset storage is full.\n");
        return;
    }

    assets[assetCount].id = readInt("Enter asset ID: ");
    readLine("Enter asset name: ", assets[assetCount].name, 50);
    assets[assetCount].value = readDouble("Enter asset value: ");
    assetCount++;
    printf("Asset added successfully.\n");
}

void listAssets(void)
{
    int i;

    if (assetCount == 0)
    {
        printf("No assets have been added.\n");
        return;
    }

    for (i = 0; i < assetCount; i++)
    {
        printf("ID: %d | Name: %s | Value: %.2f\n",
               assets[i].id, assets[i].name, assets[i].value);
    }
}

int getAssetCount(void)
{
    return assetCount;
}

void saveAssetsText(void)
{
    FILE *file = fopen(ASSET_TEXT_FILE, "w");
    int i;

    if (file == NULL)
    {
        perror(ASSET_TEXT_FILE);
        return;
    }

    for (i = 0; i < assetCount; i++)
    {
        fprintf(file, "%d|%s|%.2f\n", assets[i].id, assets[i].name, assets[i].value);
    }

    fclose(file);
    printf("%d asset record(s) saved to text file.\n", assetCount);
}

void loadAssetsText(void)
{
    FILE *file = fopen(ASSET_TEXT_FILE, "r");

    if (file == NULL)
    {
        perror(ASSET_TEXT_FILE);
        return;
    }

    assetCount = 0;
    while (assetCount < MAX_ASSETS &&
           fscanf(file, "%d|%49[^|]|%lf\n", &assets[assetCount].id,
                  assets[assetCount].name, &assets[assetCount].value) == 3)
    {
        assetCount++;
    }

    fclose(file);
    printf("%d asset record(s) loaded from text file.\n", assetCount);
}
