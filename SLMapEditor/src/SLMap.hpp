#include <string>
#include <vector>

namespace MapEditor
{
	class SLMap
	{
		public:
			SLMap(string mapdata);
			string WriteData();
			string CompileMap();
			void AddBrush(Brush newbrush);
			void AddEntity(Entity newentity);
			void DeleteEntity(string entityid);
			void MoveEntity(string entityid, int newX, int newY);
			void MoveBrush(string brushid, int newX, int newY);
			Texture2D* DrawMap(RenderTarget mapview);
		private:
			vector<Brush> brushes;
			vector<Entity> entities;
	};
}
