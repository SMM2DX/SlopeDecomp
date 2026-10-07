/**
 * @brief Barebones NN functions, such as init and nnMain.
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void nninitStartup();
void nnMain();

void _init();
void _fini();
// NOLINTNEXTLINE(bugprone-reserved-identifier)
void __nnDetailNintendoSdkRuntimeObjectFileRefer();
// NOLINTNEXTLINE(bugprone-reserved-identifier)
void __nnDetailNintendoSdkRuntimeObjectFile();
// NOLINTNEXTLINE(bugprone-reserved-identifier)
void __nnDetailNintendoSdkNsoFileRefer();

// NOLINTNEXTLINE(bugprone-reserved-identifier)
void __nnDetailNintendoSdkNsoFile_0();

#ifdef __cplusplus
}
#endif
