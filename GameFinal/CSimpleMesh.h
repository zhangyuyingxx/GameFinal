#ifndef __SIMPLE_MESH_CLASS_H__
#define __SIMPLE_MESH_CLASS_H__

#include "ISimpleMesh.h"
#include "IMaterialManager.h"
namespace gf
{
	class CSimpleMesh : public ISimpleMesh
	{
	public:
		CSimpleMesh(const std::string& name,
			u32 sortcode,
			const math::SAxisAlignedBox& aabb,
			u32 vertexFormat,
			IMeshBuffer* buffer)
			:ISimpleMesh(name, sortcode, aabb, vertexFormat)
			, mMeshBuffer(buffer)
		{

		}

		virtual void bind();

		virtual void draw() const;

		virtual void bind(IMeshBuffer* pInstanceBuffer);

		virtual void drawInstanced(u32 instanceCount) const;

		virtual IRenderableBuffer* getRenderableBuffer();

		// virtual void drawInstanced(u32 instanceCount, ) const;

		virtual E_MESH_TYPE getType() const
		{
			return EMT_SIMPLE_MESH;
		}


		virtual ~CSimpleMesh()
		{
			ReleaseReferenceCounted(mMeshBuffer);
		}

	private:
		IMeshBuffer*			mMeshBuffer;

	};
}

#endif
