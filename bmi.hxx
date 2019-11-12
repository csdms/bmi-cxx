namespace bmi {

  const int BMI_SUCCESS = 0;
  const int BMI_FAILURE = 1;

  const int MAX_COMPONENT_NAME = 2048;
  const int MAX_VAR_NAME = 2048;
  const int MAX_UNITS_NAME = 2048;
  const int MAX_TYPE_NAME = 2048;

  class Bmi {
    public:
      // Model control functions.
      virtual void Initialize(std::string config_file) = 0;
      virtual void Update() = 0;
      virtual void UpdateUntil(double time) = 0;
      virtual void Finalize() = 0;

      // Model information functions.
      virtual void GetComponentName(char * const name) = 0;
      virtual int GetInputItemCount() = 0;
      virtual int GetOutputItemCount() = 0;
      virtual void GetInputVarNames(char **names) = 0;
      virtual void GetOutputVarNames(char **names) = 0;

      // Variable information functions
      virtual int GetVarGrid(const char *name) = 0;
      virtual void GetVarType(const char *name, char *type) = 0;
      virtual void GetVarUnits(const char *name, char *units) = 0;
      virtual int GetVarItemsize(const char *name) = 0;
      virtual int GetVarNbytes(const char *name) = 0;
      virtual void GetVarLocation(const char *name, char *location) = 0;

      virtual double GetCurrentTime() = 0;
      virtual double GetStartTime() = 0;
      virtual double GetEndTime() = 0;
      virtual void GetTimeUnits(char *units) = 0;
      virtual double GetTimeStep() = 0;

      // Variable getters
      virtual void GetValue(const char *name, void *dest) = 0;
      virtual void *GetValuePtr(const char *name) = 0;
      virtual void GetValueAtIndices(const char *name, void *dest, int *inds, int count) = 0;

      // Variable setters
      virtual void SetValue(const char *name, void *src) = 0;
      virtual void SetValueAtIndices(const char *name, int *inds, int count, void *src) = 0;

      // Grid information functions
      virtual int GetGridRank(const int grid) = 0;
      virtual int GetGridSize(const int grid) = 0;
      virtual void GetGridType(const int grid, char *type) = 0;

      virtual void GetGridShape(const int grid, int *shape) = 0;
      virtual void GetGridSpacing(const int grid, double *spacing) = 0;
      virtual void GetGridOrigin(const int grid, double *origin) = 0;

      virtual void GetGridX(const int grid, double *x) = 0;
      virtual void GetGridY(const int grid, double *y) = 0;
      virtual void GetGridZ(const int grid, double *z) = 0;

      virtual int GetGridNodeCount(const int grid) = 0;
      virtual int GetGridEdgeCount(const int grid) = 0;
      virtual int GetGridFaceCount(const int grid) = 0;

      virtual void GetGridEdgeNodes(const int grid, int *edge_nodes) = 0;
      virtual void GetGridFaceEdges(const int grid, int *face_edges) = 0;
      virtual void GetGridFaceNodes(const int grid, int *face_nodes) = 0;
      virtual void GetGridNodesPerFace(const int, int *nodes_per_face) = 0;
  };
}
