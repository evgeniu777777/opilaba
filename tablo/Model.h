#ifndef MODEL_H
#define MODEL_H
/// <summary>
/// Провереят возможность отображения заставки на табло
/// </summary>
/// <param name="n">кол-во строк</param>
/// <param name="m">кол-во столбцов</param>
/// <param name="tablo">табло</param>
/// <param name="img">заставка</param>
/// <returns>Возможно ли отображение</returns>
inline bool IsDislplayable(int n, int m,const char* tablo, const char* img) {
    for (int i = 0; i < n * m; ++i) 
        if (!((tablo[i] & img[i]) ==img[i])) return 0;
    return 1;
}
#endif  MODEL_H
